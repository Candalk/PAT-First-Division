// 1075(Mooncake).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	double amounts, prices, p;
};
bool cmp(node a, node b) {
	return a.p > b.p;
}
int main()
{
	int N,total;
	double profit=0.0;
	cin >> N >> total;
	vector<node>  v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].amounts;
	for (int i = 0; i < N; i++) {
		cin >> v[i].prices;
		v[i].p = v[i].prices / v[i].amounts;
	}
	sort(v.begin(), v.end(), cmp);
	int i = 0;
	while (total > 0) {
		if (v[i].amounts <= total) {
			profit += v[i].prices;
			total = total - v[i].amounts;
		}
		else {
			profit += total*v[i].p;
			total = 0;
		}
		if(i<N-1)
			i++;
		else break;
	}

	printf("%0.2f", profit);
    return 0;
}

