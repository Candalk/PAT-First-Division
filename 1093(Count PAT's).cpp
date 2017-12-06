// 1093(Count PAT's).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int num = 0;

	vector<int> P(s.size()), T(s.size());
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A')P[i] = num;
		if (s[i] == 'P')num++;
	}
	num = 0;
	for (int i = s.size()-1; i>=0; i--) {
		if (s[i] == 'A')T[i] = num;
		if (s[i] == 'T')num++;
	}
	long long sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += P[i] * T[i];
	}
	cout << sum % 1000000007;
    return 0;
}

