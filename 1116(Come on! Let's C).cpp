// 1116(Come on! Let's C).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
bool isPrime(int k) {
	if (k == 1)
		return false;
	for (int i = 2; i <= sqrt(k); i++) {
		if (k%i == 0)return false;
	}
	return true;
}
int main()
{
	int N, rank[10002], k, checked[10002] = { 0 };
	memset(rank, -1, 10000);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> k;
		rank[k] = i;
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> k;
		if (rank[k] == -1)
			printf("%04d: Are you kidding?\n", k);
		else if (checked[k] == 1) {
			printf("%04d: Checked\n", k);
			continue;
		}
		else if (rank[k] == 1) {
			printf("%04d: Mystery Award\n", k);
		}
		else if (isPrime(rank[k])) {
			printf("%04d: Minion\n", k);
		}
		else if (rank[k] >= 1) {
			printf("%04d: Chocolate\n", k);
		}
		checked[k] = 1;
	}
	return 0;
}