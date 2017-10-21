// 1003(Emergency).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int e[510][510], //记录图
weight[510], //weight用于记录各点的权重
dis[510],//dis[i]表示从出发点到i结点最短路径的路径长度
num[510],//num[i]表示从出发点到i节点最短路径的条数
w[510];//w[i]记录从出发点到i点救援队的数目之和
bool visit[510];
const int inf = 9999999;
int main()
{

	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++)
		cin >> weight[i];
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		e[a][b] = c;
		e[b][a] = c;
	}

	dis[C1] = 0;
	w[C1] = weight[C1];
	num[C1] = 1;

	for (int i = 0; i < N; i++) {
		int u = -1, minn = inf;//u用于找下一个最短距离的点的下标，minn用于记录最短距离

		//找一个距离该点最短的且没有访问过的点
		for (int j = 0; j < N; j++) {
			if (visit[j] == false && dis[j] < minn) {//找到未访问过得点j。且j点到起始点的距离最短
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)break;//如果所有的点都访问了，停止
		visit[u] = true;//标记该点已经访问
		for (int v = 0; v < N; v++) {
			if (visit[v] == false && e[u][v] != inf) {//如果下一个点没有访问过，并且是联通的
				if (dis[u] + e[u][v] < dis[v]) {//如果从出发点到v的路径长度减少了
					dis[v] = dis[u] + e[u][v];//更新dis[v]
					num[v] = num[u];		  //并且更新最短路径路的条数
					w[v] = w[u] + weight[v];  //更新救援队的数目
				}
				else if (dis[u] + e[u][v] == dis[v]) {//如果相等，那就不用更新dis[v],只需要更新num[v]，即最短路径路的数目，还要比较权重是否增加，
					num[v] = num[v] + num[u];
					if (w[u] + weight[v] > w[v])	 //如果救援队的数目增加了，w[v] = w[u] + weight[v];
						w[v] = w[u] + weight[v];
				}
			}
		}	
	}

	printf("%d %d", num[C2], w[C2]);
    return 0;
}

