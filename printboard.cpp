#include <iostream>
#include <vector>
using std::cout;
using std::vector;

// PrintBoard function
void PrintBoard(vector<vector<int>> board)
{
  for (auto a : board)
  {
    for (int b : a)
    {
      cout << b << " ";
    }
    cout << '\n';
  }
}

int main() {
  vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0}};
  
  // PrintBoard.
  PrintBoard(board);
}