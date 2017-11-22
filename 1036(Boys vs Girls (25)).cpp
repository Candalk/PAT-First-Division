// 1036(Boys vs Girls (25)).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	string name, ID;
	int grade;
}v;
bool cmp(node a, node b) {
	return a.grade > b.grade;
}
int main()
{
	vector<struct  node> v1, v2;
	char gender;
	int N,flag=1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v.name >> gender >> v.ID >> v.grade;
		if (gender == 'F')v1.push_back(v);
		else v2.push_back(v);
	}
	sort(v1.begin(), v1.end(),cmp);
	sort(v2.begin(), v2.end(),cmp);
	if (v1.size() == 0) {
		flag = 0; 
		printf("Absent\n");
	}
	else printf("%s %s\n", v1[0].name.c_str(), v1[0].ID.c_str());

	if (v2.size() == 0) {
		flag = 0;
		printf("Absent\n");
	}
	else printf("%s %s\n", v2[v2.size()-1].name.c_str(), v2[v2.size() - 1].ID.c_str());
	if (flag == 0) {
		printf("NA\n");
	}
	else {
		printf("%d", v1[0].grade - v2[v2.size() - 1].grade);
	}
    return 0;
}

