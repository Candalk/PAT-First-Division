// 1032(Sharing (25)).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct node {
	char Data;
	int Next, flag;
}v[100001];

int main()
{
	string s1, s2;
	char Data;
	int Address,  Next,Start1,Start2,N;
	cin >> Start1 >> Start2 >> N;
	for (int i = 0; i < N; i++) {
		cin >> Address >> Data >> Next;
		v[Address].Data = Data;
		v[Address].Next = Next;
	}
	int i = Start1;
	while (i != -1) {
		v[i].flag = 1;
		s1 += v[i].Data;
		i = v[i].Next;
	}
	int j = Start2;
	while (j != -1) {
		
		if (v[j].flag == 1) {
			printf("%05d", j);
			return 0;
		}
		s2 += v[j].Data;
		j = v[j].Next;
	}
	printf("-1");
    return 0;
}

