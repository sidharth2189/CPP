/* Stack Overflow: Program that allocates so much stack memory that an overflow happens */

# include <stdio.h>

void myfunc(int k) {
    printf ("%d: current : %p \n", k, &k);
    k = k + 1;
    myfunc(k);
}

int main() {
    int i = 1;
    printf ("1 : %p \n", &i);
    
    myfunc(i);
    
    return 0;
}