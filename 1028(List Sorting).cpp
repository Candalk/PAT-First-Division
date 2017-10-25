// 1028(List Sorting).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int N, C;
struct node {
	 char name[10];
	int Grade, ID;
}V[100010];
bool cmp(node a, node b) {
	if (C == 1)return a.ID < b.ID;
	else if (C == 2) {
		if(strcmp(a.name, b.name))
		return strcmp(a.name, b.name) < 0;
		else return a.ID < b.ID;
	}
	else if (C == 3) {
		if(a.Grade != b.Grade)
			return a.Grade < b.Grade;
		else return a.ID < b.ID;
	}
		
}
int main()
{
	
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		scanf("%d %s %d", &V[i].ID, V[i].name, &V[i].Grade);
	}
	sort(V, V+N, cmp);
	for (int i = 0; i < N; i++) {
		printf("%06d %s %d\n", V[i].ID, V[i].name, V[i].Grade);
	}
    return 0;
}
 
