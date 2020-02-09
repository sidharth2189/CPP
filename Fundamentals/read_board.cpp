#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::ifstream;
using std::cout;
using std::string;
using std::vector;

// ReadBoardFile function
void ReadBoardFile(string str)
{
  ifstream my_file;
  my_file.open(str);
  string line;
  if (my_file) 
  {
    cout << "The file stream has been created!" << "\n";
    while (getline(my_file, line))
    {
      cout << line << '\n';
    }
  }
}

int main() 
{
  // Call ReadBoardFile function
  ReadBoardFile("files/1.board");
}