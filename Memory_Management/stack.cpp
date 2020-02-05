/*
    Automatic memory allocation
    Program helps observe the expansion and contraction of stack as Process Memory Model
*/

# include <stdio.h>

void myfunc() {
    int k = 3;
    printf ("3 : %p \n", &k);
}

int main() {
    int i = 1;
    printf ("1 : %p \n", &i);

    int j = 2;
    printf ("2 : %p \n", &j);

    myfunc();

    int l = 4;
    printf ("4 : %p \n", &l);

    return 0;
}