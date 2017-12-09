// 1133(Splitting A Linked List).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct node {
	int Data, Next;
}V[100001];
int main()
{
	int start, N, K;
	cin >> start >> N >> K;

	for (int i = 0; i < N; i++) {
		int Address, Data, Next;
		cin >> Address>>Data>>Next;
		V[Address].Data = Data;
		V[Address].Next = Next;
	}
	int flag = 1;
	for (int i = start;i!=-1;) {
		if (V[i].Data < 0) {
			if (flag == 1) {
				printf("%05d %d ", i, V[i].Data);
				flag = 0;
			}
			else printf("%05d\n%05d %d ", i, i, V[i].Data);
		}
		i = V[i].Next;
	}
	for (int i = start; i != -1;) {
		if (V[i].Data >= 0 && V[i].Data <= K) {
			if (flag == 1) {
				printf("%05d %d ", i, V[i].Data);
				flag = 0;
			}
			else {
				printf("%05d\n%05d %d ", i, i, V[i].Data);
			}
		}
		i = V[i].Next;
	}
	for (int i = start; i != -1;) {
		if (V[i].Data > K) {
			if (flag == 1) {
				printf("%05d %d ", i, V[i].Data);
				flag = 0;
			}
			else {
				printf("%05d\n%05d %d ", i, i, V[i].Data);
			}
		}
		i = V[i].Next;
	}
	printf("-1");
    return 0;
}

