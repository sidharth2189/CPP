#include <stdio.h> 
#include <stdlib.h> 

int main()
{
    // Generates memory leak
    int *m = (int*)malloc(sizeof(int)); 
    m = NULL; 

    // Uses a dangling pointer
    int *n = (int*)malloc(sizeof(int)); 
    free(n);
    *n = 23;

    // Uses uninitialized pointer
    char *o;
    *o = 'a'; 

    return 0;
}