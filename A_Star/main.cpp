#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::sort;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

enum class State {kStart, kFinish, kEmpty, kObstacle, kClosed, kPath};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// TODO: Write function to compare the f-value of two nodes here
bool Compare(vector<int> node1, vector<int> node2)
{
  if (node1[2] + node1[3] > node2[2] + node2[3])
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

// TODO: Write CheckValidCell here. Check that the 
// cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
  if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == State::kEmpty)
  {
    return true;
  }
  else
  {
    return false;
  } 
}

// TODO: Write the AddToOpen function here.
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<State>> &grid)
{
    vector<int> node = {x, y, g, h};
    open.push_back(node);
    grid[x][y] = State::kClosed;
}

/** 
 * Expand current nodes's neighbors and add them to the open list.
 */
// TODO: ExpandNeighbors(arguments) {

  // TODO: Get current node's data.

  // TODO: Loop through current node's potential neighbors.

    // TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.

      // TODO: Increment g value, compute h value, and add neighbor to open list.

// } TODO: End the function
void ExpandNeighbors(vector<int> &current_node, int goal[2], vector<vector<int>> &open, vector<vector<State>> &grid)
{
  int x = current_node[0];
  int y = current_node[1];
  int g = current_node[2];
  int h = current_node[3];
  
  int directions = sizeof(delta)/sizeof(delta[0]);

  for (int index = 0; index < directions; index++)
  {
    int x_new = x + delta[index][0];
    int y_new = y + delta[index][1];
    if (CheckValidCell(x_new, y_new, grid))
    {
      int g_new = g + 1;
      int h_new = Heuristic(x_new, y_new, goal[0], goal[1]);
      AddToOpen(x_new, y_new, g_new, h_new, open, grid);  
    }
  }
}

/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};
  
  // TODO: Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  
  // TODO: Use AddToOpen to add the starting node to the open vector.
  AddToOpen(x, y, g, h, open, grid);

  // TODO: while open vector is non empty {
  while(!open.empty())
  {

      // TODO: Sort the open list using CellSort, and get the current node.
      CellSort(&open);
      vector<int> current_node = open.back();
      // TODO: Get the x and y values from the current node,
      // and set grid[x][y] to kPath.
      open.pop_back();
      int x = current_node[0];
      int y = current_node[1];
      grid[x][y] = State::kPath;
      
      // TODO: Check if you've reached the goal. If so, return grid.
      if (x == goal[0] && y == goal[1])
      {
          grid[init[0]][init[1]] = State::kStart;
          grid[goal[0]][goal[1]] = State::kFinish;
          return grid;
      }
      
      // If we're not done, expand search to current node's neighbors.
      // ExpandNeighbors
       ExpandNeighbors(current_node, goal, open, grid);
  
  //} // TODO: End while loop
  }

  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦   ";
    case State::kFinish: return "🏁   "; 
    default: return "0   "; 
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

#include "test.cpp"

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
  TestAddToOpen();
  TestCompare();
  TestSearch();
  TestCheckValidCell();
  TestExpandNeighbors();
}