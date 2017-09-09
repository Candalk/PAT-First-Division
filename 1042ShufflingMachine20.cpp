#include<iostream>
#include<string>
using namespace std;
int main()
{
	int K, a[55] = { 0 },n=1;
	string S1[55] , S2[55],S="SHCD";
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <=13; j++) {
			S1[n++] = S[i] + to_string(j);
		}
	}
	S1[n++] = "J1"; S1[n++] = "J2";

	/*for (int i = 1; i < 55; i++) {
		cout << S1[i] << " ";
	}*/
	cin >> K;
	for (int i = 1; i < 55; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < K; i++) {
		for (int j = 1; j < 55; j++) {
			S2[a[j]] = S1[j];
		}
		for (int j = 1; j < 55; j++) {
			S1[j] = S2[j];
		}
	}
	for (int i = 1; i <55; i++) {
		if (i == 1)cout << S2[i];
		else 
		cout <<" "<< S2[i];
	}
    return 0;
}

