// 1002ABforPolynomials252.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int K,N,num=0;
	float f[1001] = { 0 },a;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> a;
		f[N] += a;
	}
	
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> a;
		f[N] += a;
	}
	for (int i = 0; i < 1001; i++)
		if (f[i])num++;
	cout << num;

	for (int i = 1000; i >= 0; i--) {
		if (f[i])printf(" %d %0.1f", i, f[i]);
	}
    return 0;
}

