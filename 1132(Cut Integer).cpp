// 1032(Cut Integer).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	long long int Z, A, B;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		Z = stoll(s);
		A = stoll(s.substr(0, s.size() / 2));
		cout << s.substr(0, s.size() / 2) << endl;
		B = stoll(s.substr(s.size() / 2+1, s.size()));
		cout << s.substr(s.size() / 2 , s.size()-1) << endl;
		printf("Z = %d , A = %d , B = %d\n",Z,A,B);
	}

    return 0;
}

