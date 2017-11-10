// 1030(Travel Plan).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int inf = 99999999;
int dis[510],pre[510],visited[510],e[510][510],Cost[510][510], C[510];
int N, M, S, D;
void print(int End) {
	if (End != S)
		print(pre[End]);
	printf("%d ", End);
}
int main()
{

	fill(dis, dis + 510, inf);
	fill(C, C + 510, inf);
	fill(visited, visited + 510, false);
	fill(e[0], e[0] + 510 * 510, inf);
	fill(Cost[0], Cost[0] + 510 * 510, inf);
	cin >> N >> M >> S >> D;

	for (int i = 0; i < M; i++) {
		int c1, c2, Dis, cost;
		cin >> c1 >> c2 >> Dis >> cost;
		e[c1][c2] = e[c2][c1] = Dis;
		Cost[c1][c2] = Cost[c2][c1] = cost;
	}

	for (int i = 0; i < N; i++) {
		pre[i] = i;
		e[i][i] = 0;
		Cost[i][i] = 0;

		if (e[S][i] != inf) {
			C[i] = Cost[S][i];
			dis[i] = e[S][i];
			pre[i] = S;
		}
	}
	
	for (int i = 0; i < N; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < N; j++) {
			if (visited[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)break;
		visited[u] = true;

		for (int v = 0; v < N; v++) {
			if (dis[v] > dis[u] + e[u][v]) {
				dis[v] = dis[u] + e[u][v];
				C[v] = C[u] + Cost[u][v];
				pre[v] = u;
				visited[v] = true;
			}
			else if (dis[v] == dis[u] + e[u][v] && C[v]>C[u] + Cost[u][v]) {
				C[v] = C[u] + Cost[u][v];
				pre[v] = u;
				visited[v] = true;
			}
		}
	}
	print(D);
	printf("%d %d", dis[D], C[D]);
	return 0;
}