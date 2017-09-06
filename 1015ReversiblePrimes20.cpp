// 1015ReversiblePrimes20.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
bool isprime(int n) {
	if (n == 1)return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return true;
}
int toRadixD(int N,int D) {
	char s[100]=""; int i = 0;
	while (N) {
		s[i] = N%D+'0';
		N = N / D;
		i++;
	}
	int sum = 0;
	for (int j = 0; j < i; j++) {
		sum = (s[j]-'0')  + sum* D;
	}
	//cout << sum << endl;
return sum;
}
int main()
{
	int N, D,reseveral;
	cin >> N ;
	while (N >= 0) {
		cin >> D;
		if (isprime(N) == false) {
			cout << "NO" << endl;
			cin >> N;
			continue;
		}
		reseveral = toRadixD(N, D);
		if (isprime(reseveral)) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
		cin >> N;
	}
    return 0;
}

