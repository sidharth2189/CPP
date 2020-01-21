/* Add using a function */ 

# include <iostream>
using std::cout;

// Function declaration and definition
int addfunc(int i, int j)
{
    return i + j;
}

int main()
{
    auto a = 4;
    auto b = 6;
    cout << addfunc(a, b) << '\n';
}