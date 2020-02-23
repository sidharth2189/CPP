/*
    Implement a void function F that takes pointers to two arrays of 
    integers (A and B) and a size N as parameters. It then populates B 
    where B[i] is the product of all A[j] where j != i.

    For example: If A = {2, 1, 5, 9}, then B would be {45, 90, 18, 10}
*/

# include <iostream>
using namespace std;

void F(int* A, int* B, int N) {
    for (int i = 0; i < N; ++i) {
        B[i] = 1;
        for (int j = 0; j < N; j++)
        {
            if (j != i)
            {
                B[i] = B[i] * A[j];
            }
        }
    }
}

int main(){
    int A[] = {2, 0, 5, 9};
    int N = sizeof(A)/sizeof(int);
    int B[N];
    F(A, B, N);
    
    cout << "A is ";
    for (const auto& value: A) {
		cout << value << ' ';
	}

    cout << "\nB is ";
    for (const auto& value: B) {
		cout << value << ' ';
	}
}