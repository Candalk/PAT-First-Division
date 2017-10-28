// 1075(PAT Judge).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
������ҵĴ���㣺
1.perfectly����������˼��Ҳ����˵�������֣���ȴ������Ϊ����߷ֵ������������˰�
2.���е���ô�죿û�аѲ��е�����Ū����ͬ�ģ�ɵ�˰�
3.����Ҫ�����ĳ�����ύ�ˣ�����ûͨ������������ʱ��ɼ���Ϊ0��������-1��
Ϊ�˺÷ֱ棬������������Ǳ�ǳɼ�Ϊ-2��û�н�����Ϊ-1�������ʱ��ֱ�һ�¼���
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

