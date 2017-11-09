// 1033(To Fill or Not to Fill)2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	double dis, price;
};
bool cmp(node a, node b) {
	return a.dis < b.dis;
}
const int inf = 99999999;
int main()
{
	int Cmax, D, Davg, N;
	cin >> Cmax >> D >> Davg >> N;
	vector<node> v(N+1);
	v[0].price = 0;
	v[0].dis = D;
	for (int i = 1; i <=N; i++)
		cin >> v[i].price >> v[i].dis;
	sort(v.begin(), v.end(), cmp);
	double  nowdis = 0, maxdis = 0, nowprice=0, totalprice=0, leftdis = 0;//Y表示油箱中剩余的油量
	if (v[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else {
		nowprice = v[0].price;
	}
	
	while (nowdis < D) {
		maxdis = nowdis + Cmax*Davg;
		double minPriceDis = 0, minprice = inf;
		int flag = 0;
		for (int i = 1; i <= N&&v[i].dis <= maxdis; i++) {
			if (v[i].dis <= nowdis)continue;
			if (v[i].price < nowprice) {
				totalprice += (v[i].dis - nowdis - leftdis)*nowprice / Davg;
				leftdis = 0;
				nowprice = v[i].price;
				nowdis = v[i].dis;
				flag = 1;
				break;
			}
			if (v[i].price < minprice) {
				minprice = v[i].price;
				minPriceDis = v[i].dis;
			}
		}
		if (flag == 0 && minprice != inf) {
			totalprice += (nowprice*(Cmax-leftdis/Davg));
			leftdis = Cmax*Davg - (minPriceDis - nowdis);
			nowprice = minprice;
			nowdis = minPriceDis;
		}
		if (flag == 0 && minprice == inf) {
			nowdis += Cmax*Davg;
			printf("The maximum travel distance = %.2f", nowdis);
			return 0;
		}
	}
	printf("%0.2f", totalprice);
    return 0;
}

