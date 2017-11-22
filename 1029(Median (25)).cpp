// 1029(Median (25)).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
long long int v1[1000001],v2[1000001],v[1000001];
int main()
{
	
	int N1,N2,i,j,k;
	cin >> N1;
	for ( i = 0; i < N1; i++)cin >> v1[i];
	cin >> N2;
	for ( i = 0; i < N2; i++)cin >> v2[i];
	i = 0; j = 0;k=0;
	while (i < N1&&j < N2) {
		if (v1[i] < v2[j]) 
			v[k++] = v1[i++];
		if(v1[i]>=v2[j])
			v[k++] = v2[j++];
	}
	while (i < N1)v[k++] = v1[i++];
	while (j < N2)v[k++] = v2[j++];
	//for (int j = 0; j < N1+N2; j++)cout << v[j] << " ";
	cout << v[(N1+N2 - 1) / 2];
    return 0;
}

