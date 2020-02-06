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