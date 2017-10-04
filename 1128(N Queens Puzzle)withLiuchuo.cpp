// 1128(N Queens Puzzle)withLiuchuo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	int K, N;
	cin >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> N;
		vector<int> v(N);
		bool flag = true;
		for (int j = 0; j < N; j++) {
			cin >> v[j];
			for (int t = 0; t < j; t++)
				if (v[j] == v[t] || abs(v[j] - v[t]) == abs(j - t)) flag = false;
		}
		cout << (flag == true ? "YES\n" : "NO\n");
	}
    return 0;
}

