// 1105(Spiral Matrix ).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int N, m, n;
	scanf("%d", &N);
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end(), cmp);
	int min = 99999999;
	for (int i = 1; i <= sqrt(N); i++) {	
		if (N%i == 0) {
			int j = N / i;
			if (j>=i&&j - i < min) {
				min = j - i;
				m = j;
				n = i;
			}		
		}
	}
	//printf("m = %d, n = %d\n", m, n);
	vector<vector<int>> b(m, vector<int>(n));
	int level = m / 2 + m % 2,t=0;
	for (int i = 0; i < level; i++) {
		for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
			b[i][j] = a[t++];
		for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
			b[j][n - 1 - i] = a[t++];
		for (int j = n - i - 1; j >= i && t <= N - 1; j--)
			b[m - 1 - i][j] = a[t++];
		for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
			b[j][i] = a[t++];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0)
				printf("%d", b[i][j]);
			else printf(" %d", b[i][j]);
		}
		printf("\n");
	}
    return 0;
}

