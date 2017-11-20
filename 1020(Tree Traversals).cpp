// 1020(Tree Traversals).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int post[31], in[31], a[1000000] = { 0 };
int N;
void traversal(int index,int root,int m,int n) {
	if (m > n)return;
	int k = m;
	while (k<n&&in[k] != post[root])k++;
	a[index] = post[root];
	traversal(index*2+1,root-(n-k)-1,m, k - 1);//注意根节点
	traversal(index * 2 + 2, root-1,k + 1, n);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> post[i];
	for (int i = 0; i < N; i++)
		cin >> in[i];
	traversal(0,N-1,0,N-1);
	int num = 0;
	for (int i = 0; i < 1000000&&num<N; i++) {
		if (a[i] != 0 && num == 0) { cout << a[i]; num++; }
		else if (a[i] != 0) { cout << " " << a[i]; num++; }
	}
    return 0;
}

