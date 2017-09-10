// 1046ShortestDistance20.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int N, M,m,n,D,a[100001] = { 0 },sum=0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> D;
		sum += D;
		a[i] = sum;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m >> n;
		int temp;
		if (m > n) swap(m, n);
	 if (a[n-1]-a[m-1] <sum-(a[n-1] - a[m-1]))
		 cout << a[n-1] - a[m-1] << endl;
	 else cout << sum - (a[n-1] - a[m-1]) << endl;
	}
    return 0;
}

