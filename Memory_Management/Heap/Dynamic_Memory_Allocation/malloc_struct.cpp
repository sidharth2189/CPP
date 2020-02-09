
#include <stdio.h> 
#include <stdlib.h> 

struct MyStruct {
    int i; 
    double d; 
    char a[5];
};
  
int main() 
{ 
    int number = 4, index = 0;
    MyStruct *p = (MyStruct*)malloc(number*sizeof(int));
    for (index = 0; index < number; index++)
    {
       p[index].i = index;
       p[index].d = 3.14;
       p[index].a[0] = 'a';
       printf("address=%p\n", (p+index)); 
    }
    
    return 0; 
}