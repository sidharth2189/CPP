//Write a C++ function to swap two integers without
//using a temp variable. 

# include <iostream>
using namespace std;

void swapInt(int *p, int *q)
{
    if (p == q)
    {
        return;
    }
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}

int main()
{
    int a = 1;
    int b = 2;
    cout << "Before swap, a = " << a << " & b = " << b << endl;
    swapInt(&a, &b);
    cout << "After swap, a = " << a << " & b = " << b << endl;
}