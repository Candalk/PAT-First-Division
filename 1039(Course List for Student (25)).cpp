// 1039(Course List for Student (25)).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long getID(char  *s) {
	long sum = 0;
	for (int i = 0; i < 3; i++) 
		sum =sum*26+ s[i] - 'A';
	sum = sum * 10+ s[3] - '0';
	return sum;
}
const int maxnum = 26 * 26 * 26*10 + 10;
vector<int> m[maxnum];
int main()
{
	
	int N, K;
	char name[5];
	cin >> N >> K;
	for(int i=0;i<K;i++){
		int Ci, Ni;
		scanf("%d %d", &Ci, &Ni);
		for (int j = 0; j < Ni; j++) {
			scanf("%s", name);
			long id = getID(name);
			m[id].push_back(Ci);
		}
	}
	for (int i = 0; i < N; i++) {
		  
		cin >> name;
		long id = getID(name);
		printf("%s %d", name, m[id].size());
		sort(m[id].begin(), m[id].end());
		for (int j = 0; j < m[id].size(); j++) {
			printf(" %d", m[id][j]);
		}
		printf("\n");
	}
    return 0;
}
 
