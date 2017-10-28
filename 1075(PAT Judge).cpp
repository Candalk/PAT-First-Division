// 1075(PAT Judge).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
这道题我的错误点：
1.perfectly是完整的意思，也就是说得了满分，我却他妈以为是最高分的题号数，抽筋了吧
2.并列的怎么办？没有把并列的排名弄成相同的，傻了吧
3.按照要求，如果某个人提交了，但是没通过编译器，这时候成绩记为0，而不是-1，
为了好分辨，这种情况下我们标记成绩为-2，没有交过的为-1，输出的时候分辨一下即可
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int id, p_id, p_score, total_score, p[6], flag, perfect,rank;
};
bool cmp(node a, node b) {
	if (a.total_score != b.total_score) {
		return a.total_score > b.total_score;
	}
	else if (a.perfect != b.perfect) {
		return a.perfect > b.perfect;
	}
	else return a.id < b.id;
}
int main()
{
	int N, K, M, P[6];
	scanf("%d %d %d", &N, &K, &M);
	vector<node> v(N + 1);
	for (int i = 1; i <= K; i++)
		scanf("%d", &P[i]);
	for (int i = 0; i <= N; i++) {
		fill(v[i].p, v[i].p + 6, -1);
		v[i].flag = 0;
	}
	for (int i = 0; i < M; i++) {
		int id, p_id, p_score;
		scanf("%d %d %d", &id, &p_id, &p_score);
		v[id].id = id;
		if (v[id].p[p_id] < p_score) {
			v[id].p[p_id] = p_score;
		}
		if (p_score != -1) {
			v[id].flag = 1;
		} else if(v[id].p[p_id]==-1){
			v[id].p[p_id] = -2;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if(v[i].p[j]!=-1&&v[i].p[j]!=-2)
				v[i].total_score += v[i].p[j];
			if (v[i].p[j] == P[j])v[i].perfect++;
		}
	}
	int rank = 1;
	sort(v.begin()+1, v.end(), cmp);
	for (int i = 1; i <= N; i++) {
		v[i].rank = i;
		if (i != 1 && v[i].total_score == v[i - 1].total_score) {
			v[i].rank = v[i - 1].rank;
		}
	}
	for (int i = 1; i <=N; i++) {
		if (v[i].flag) {
			printf("%d %05d %d", v[i].rank, v[i].id, v[i].total_score);
			for (int j = 1; j <= K; j++) {
				if (v[i].p[j] != -1&& v[i].p[j] != -2)
					printf(" %d", v[i].p[j]);
				else if(v[i].p[j] == -2)printf(" 0");
				else printf(" -");
			}
			printf("\n");
		}
		
	}
	return 0;
}

