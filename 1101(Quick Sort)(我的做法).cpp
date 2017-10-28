// 1101(Quick Sort).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N, a[100010], LeftMax[100010], RightMin[100010];//LeftMax数组用于记录当前左边最大数，RightMin数组用于记录当前右边最小数
	scanf("%d", &N);
	int big = -1, small = 9999999999;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		if (i == 1) {
			LeftMax[1] = a[1] - 1;
			continue;
		}
		if (a[i] > big) {
			LeftMax[i + 1] = a[i];
			big = a[i];
		}
		else LeftMax[i + 1] = LeftMax[i];
	}
	RightMin[N] = a[N] + 1;
	for (int i = N; i >= 1; i--) {
		if (a[i] < small) {
			RightMin[i - 1] = a[i];
			small = a[i];
		}
		else RightMin[i - 1] = RightMin[i];
	}

	vector<int> v;
	for (int i = 1; i <= N; i++) {
		if (a[i] <= RightMin[i] && a[i] >= LeftMax[i]) {
			v.push_back(a[i]);
		}
	}
	printf("%d\n", v.size());
	sort(v.begin(), v.end());
	int flag = 1;
	for (int i = 0; i < v.size(); i++) {
		if (flag) {
			printf("%d", v[i]);
			flag = 0;
		}
		else {
			printf(" %d", v[i]);
		}
	}
	printf("\n");
	return 0;
}