// 1125(Chain the Ropes).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum = (sum + v[i])*1.0 / 2;
	}
	
	printf("%d", int(sum));
    return 0;
}

