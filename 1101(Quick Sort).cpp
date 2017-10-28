// 1101(Quick Sort).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N, a[100010], b[100010];
	scanf("%d", &N);
	int big = -1, small = 9999999999;

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(a, a + N);
	vector<int> v;
	int max = 0, cnt = 0;
	for (int i = 0; i <N; i++) {
		if (a[i] == b[i] && b[i]>max) {
			v.push_back(b[i]);
		}
		if (b[i] > max)
			max = b[i];
	}
	printf("%d\n", v.size());

	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			printf("%d", v[i]);
		}
		else {
			printf(" %d", v[i]);
		}
	}
	printf("\n");
	return 0;
}