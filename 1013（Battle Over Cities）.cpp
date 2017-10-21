// 1013（Battle Over Cities）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int e[1001][1001],visit[1001];
int N, M, K,a,b;
void dfs(int node) {
	visit[node] = true;
	for (int i = 1; i <= N; i++)
		if (visit[i] == false && e[node][i] == 1)
			dfs(i);
	
}
int main()
{

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		e[a][b] = e[b][a] = 1;
	}
	for (int i = 0; i < K; i++) {
		fill(visit, visit + 1001, false);
		b=0;
		cin >> a;
		visit[a] = true;
		for (int j = 1;j <= N; j++) {
			if (visit[j] == false) {
				dfs(j);
				b++;
			}	
		}
		cout << b - 1<<endl ;
	}
    return 0;
}

