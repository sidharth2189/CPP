#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;

// TODO: Add the ParseLine function here.
vector<int> ParseLine(string str)
{
    istringstream my_stream(str);
    char c;
    int n;
    vector<int> vec;
    while (my_stream >> n >> c) 
    {
        vec.push_back(n);
    }

    return vec;
}

// TODO: Change the return type of ReadBoardFile.
vector<vector<int>> ReadBoardFile(string path) 
{
  ifstream myfile (path);
  // TODO: Declare an empty board variable here with
  // type vector<vector<int>>.
  vector<vector<int>> board{};
  vector<int> row;
  if (myfile) 
  {
    string line;
    while (getline(myfile, line))
    {
      // TODO: Replace the "cout" code with a call to ParseLine for each line and push the results of ParseLine to the back of the board.
      row = ParseLine(line);
      board.push_back(row);
    }
  }
  // TODO: Return the board variable.
  return board;
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

#include "test.cpp" // For testing.

int main() 
{
  vector<vector<int>> board = ReadBoardFile("files/1.board");
//   TestParseLine(); // For testing.
  // Leave commented out.
  PrintBoard(board);
}