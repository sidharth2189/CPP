# include <iostream>
using std::cout;
using std::endl;

int main() 
{

    int x;
    int y;
    int *p = &x;
    int *q = &y;

    x = 35;
    y = 46;

    p = q;

    // *p = 90;

    cout << x << " " << y << endl;
    cout << *p << " " << *q << endl;
    cout << "Address of p = " << p << endl;
    cout << "Address of q = " << q << endl;
}