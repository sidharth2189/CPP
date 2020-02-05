/* 
    Program that checks the memory utilization on stack with respect to 
    various ways of passing parameter to function
*/

#include <stdio.h>
#include <vector>
using std::vector;
    
void CallByValue(vector<int> i)
{
    int j = 1; 
    printf ("call-by-value: %p\n",&j);
}

void CallByPointer(vector<int> *i)
{
    int j = 1; 
    printf ("call-by-pointer: %p\n",&j);
}

void CallByReference(vector<int> &i)
{
    int j = 1; 
    printf ("call-by-reference: %p\n",&j);
}

int main()
{
    vector<int> i = {1,3,4,0,8};
    vector<int> * j;
    j = &i;
    printf ("stack bottom: %p\n",&i);
    
    CallByValue(i);

    CallByPointer(j);

    CallByReference(i);

    return 0;
}