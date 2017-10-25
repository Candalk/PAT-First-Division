// 1016（Phone Bills）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int cost[25] = { 0 }, month, day, hour, minute, N;
struct Phone_Bills {
	string name;
	int month, day, hour, minute,status,time;
};
bool cmp(Phone_Bills a, Phone_Bills b) {
	if(a.name!=b.name)
		return a.name < b.name;
	return  a.time < b.time;
}
double rate(Phone_Bills a) {
	double total = cost[a.hour] * a.minute + cost[24] * 60 * a.day;
	for (int i = 0; i < a.hour; i++)
		total += cost[i] * 60;
	return total / 100.0;
}
int main()
{
	
	string name, flag;
	for (int i = 0; i < 24; i++) {
		cin >> cost[i];
		cost[24] += cost[i];
	}
		
	cin >> N;
	vector<Phone_Bills> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
		cin >> flag;
		if (flag == "on-line")data[i].status = 1;
		else data[i].status = 0;
		data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;	
	}
	sort(data.begin(), data.end(),cmp);

	map<string, vector<Phone_Bills>> custom;
	for (int i = 1; i < N; i++) {
		if (data[i].name == data[i - 1].name&&data[i-1].status == 1 && data[i].status == 0) {
			custom[data[i - 1].name].push_back(data[i - 1]);
			custom[data[i].name].push_back(data[i]);
		}
	}

	for (auto it : custom) {
		vector<Phone_Bills> temp = it.second;
		cout << it.first;
		printf(" %02d\n",temp[0].month);
		double total = 0;
		for (int i = 1; i < temp.size(); i += 2) {
			double t = rate(temp[i])- rate(temp[i-1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%0.2lf\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i ].time - temp[i-1].time, t);
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}

