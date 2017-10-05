#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char A[100], B[100];
    bool hash[128] = { false };
    cin >> A >> B;
    int a, b, i;
    a = strlen(A);
    b = strlen(B);
    for (i = 0; i < b; i++) {
        if (B[i] >= 'a'&&B[i] <= 'z')
            B[i] = B[i] - 32;
        if (hash[B[i]] == false)
            hash[B[i]] = true;
    }
    for (i = 0; i < a; i++) {
        if (A[i] >= 'a' && A[i] <= 'z')
            A[i] = A[i] - 32;
        if (hash[A[i]] == false) {
            cout << A[i];
            hash[A[i]] = true;
        }
    }
    return 0;
}