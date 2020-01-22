/*
    Steps to read file
    1) #include <fstream>
    2) Create a std::ifstream object using the path to your file.
    3) Evaluate the std::ifstream object as a bool to ensure that the stream creation did not fail.
    4) Use a while loop with getline to write file lines to a string.
*/

#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream my_file;
    my_file.open("files/1.board");
    std::string line;
    if (my_file) 
    {
      std::cout << "The file stream has been created!" << '\n';
      while (getline(my_file, line))
      {
          std::cout << line << '\n';
      }
    }    
}