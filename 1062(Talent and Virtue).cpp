// 1062(Talent and Virtue).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
struct node {
	int ID, Virtue, Talent;
}V;
bool cmp(node a, node b) {
	int sum1 = a.Virtue + a.Talent, sum2 = b.Virtue + b.Talent;
	if (sum1 != sum2)
		return sum1 > sum2;
	else if (a.Virtue != b.Virtue)
		return a.Virtue > b.Virtue;
	else return a.ID<b.ID;

}
int main()
{
	int N, L, H,M=0;
	scanf("%d %d %d", &N, &L, &H);
	//vector<node> V(N);
	M = N;
	vector<node> P[4];
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &V.ID, &V.Virtue, &V.Talent);
		if(V.Talent >=L&&V.Virtue >=L){
			if (V.Virtue >= H&&V.Talent >= H) {
				P[0].push_back(V);
			}
			else if (V.Talent < H&&V.Virtue >= 80) {
				P[1].push_back(V);
			}
			else if (V.Talent < H&&V.Virtue < H&&V.Virtue >= V.Talent) {
				P[2].push_back(V);
			}
			else{
				P[3].push_back(V);
			}
		}
		else M--;
	}
	//printf("\n");
	printf("%d\n", M);
	for (int i = 0; i < 4; i++) {
		sort(P[i].begin(), P[i].end(), cmp);
		for (int j = 0; j < P[i].size(); j++) {
			printf("%d %d %d\n", P[i][j].ID, P[i][j].Virtue, P[i][j].Talent);
			
		}
		//printf("\n");
	}
    return 0;
}

