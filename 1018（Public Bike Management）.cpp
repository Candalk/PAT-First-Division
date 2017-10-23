// 1018（Public Bike Management）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
const int inf = 99999999;
int e[510][510];
int weight[510];
int dis[510];
int minNeed = inf, minBack = inf;
bool visit[510];
vector<int> pre[510];
vector<int> path, temppath;
void dfs(int v) {
	if (v == 0) {
		temppath.push_back(v);
		int need = 0, back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--) {
			int id = temppath[i];
			if (weight[id] > 0) {
				back += weight[id];
			}else {
				if (back > (0 - weight[id])) {
					back += weight[id];
				}else {
					need += ((0 - weight[id]) - back);
					back = 0;
				}
			}
		}
		if (need < minNeed) {
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need = minNeed&&back < minBack) {
			minBack = back;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
		dfs(pre[v][i]);
	temppath.pop_back();
}
int main()
{
	int Cmax, N, Sp, M;

	fill(e[0], e[0] + 510 * 510, inf);
	cin >> Cmax >> N >> Sp >> M;
	fill(dis, dis + 510, inf);
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
		weight[i] = weight[i] - Cmax / 2;
	}
		
	for (int i = 0; i < M; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		e[a][b] = e[b][a] = dist;
	}
	dis[0] = 0;
	for (int i = 0; i <= N; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j <= N; j++) {
			if (visit[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}

		if (u == -1)
			break;
		visit[u] = true;
		for (int v = 0; v <= N; v++) {
			if (visit[v] == false && e[u][v] != inf) {
				if ( dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[v] == dis[u] + e[u][v]) {
					pre[v].push_back(u);
				}
			}
			
		}
	}

	/*for (int i = 0; i <= N; i++) {
		printf("%d = %d\n", i, dis[i]);
	}*/
	/*for (int i = 0; i <= N; i++) {
		printf("%d = %d\n", i, pre[i]);
	}*/
	dfs(Sp);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--)
		printf("->%d", path[i]);
	printf(" %d", minBack);
    return 0;
}

