/*
    The pointer p2 in the example is invalid as soon as free(p) is called. 
    It still holds the address to the memory location which has been freed, 
    but may not access it anymore. Such a pointer is called a "dangling pointer".
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *p = malloc(100);
    void *p2 = p;
    printf("%p\n",p);
    free(p);
    // Freeing twice could lead to dangling pointer
    printf("%p\n",p2);
    free(p2);

    return 0;
}