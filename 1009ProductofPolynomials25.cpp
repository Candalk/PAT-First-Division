#include<iostream>
using namespace std;
int main()
{
	int K,N,m;
	float A[1001] = { 0 }, B[2001] = { 0 }, C[2001] = { 0 },a,n; 

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> a;
	//	cout << N << " " << a << endl;
		A[N] = a;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> a;
		//cout << N << " " << a << endl;

		for (int j = 0; j < 1001; j++) {
			if (A[j]) {
				//cout << "A[" << j << "]=" << A[j] << endl;
				m = N + j;
				n = A[j] * a;
				B[m] = B[m] + n;
				//cout << "B[" << m << "]=" << B[m] << endl;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++)
		if (B[i])count++;
	cout << count; 
	for (int i = 2000; i >=0; i--) {
		if (B[i]) {
			printf(" %d %0.1f", i, B[i]);
		}
	}

    return 0;
}

