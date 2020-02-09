#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int number = 3, index = 0;
    int *p = (int*)malloc(number*sizeof(int));
    for (index = 0; index < number; index++)
    {
       p[index] = index;
       printf("address=%p, value=%d\n", (p+index), *(p+index)); 
    }
    
    return 0; 
}