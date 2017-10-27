// 1055(The World's Richest).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	char name[9];
	int age, net_worth;
};
bool cmp1(node a, node b) {

	if (a.net_worth != b.net_worth)
		return a.net_worth > b.net_worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else return(strcmp(a.name,b.name)<0);
}
int main()
{
	
	int N, K;
	scanf("%d %d", &N, &K);
	vector<node> P(N), V;//P����ͳ��ԭʼ���ݣ�V��¼ɸѡ�������
	int book[201] = { 0 };
	for (int i = 0; i < N; i++) 
		scanf("%s %d %d", P[i].name, &P[i].age, &P[i].net_worth);
	
	sort(P.begin(), P.end(), cmp1);//ֱ�Ӱ�������Ҫ������

	for (int i = 0; i < N; i++) {//ÿ������ȡǰһ��������ΪM<=100,ÿ��������100���ˣ����û����һ���ᳬʱ
		if (book[P[i].age] <= 100) {
			V.push_back(P[i]);
			book[P[i].age]++;
		}
	}
	for (int i = 1; i <=K; i++) {
		int M, Amin, Amax;
		scanf("%d %d %d", &M, &Amin, &Amax);
		vector<node> v;//v���ڼ�¼���Ľ��
		for (int j = 0; j < V.size(); j++) {
			if (V[j].age >= Amin&&V[j].age <= Amax) {//����Ҫ���ѹ��v��
				v.push_back(V[j]);
			}
		}
		printf("Case #%d:\n", i);
		for (int j = 0; j < M&&j < v.size(); j++) {
			printf("%s %d %d\n", v[j].name, v[j].age, v[j].net_worth);
		}
		if (v.size() == 0) {
			printf("None\n");
		}
	}
    return 0;
}

