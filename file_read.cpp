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
      std::cout << "The file stream has been created!" << "\n";
      while (getline(my_file, line))
      {
          std::cout << line << '\n';
      }
    }    
}