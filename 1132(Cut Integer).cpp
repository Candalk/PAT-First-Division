// 1132(Cut Integer).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s, s1, s2;
	long long int N, Z,A,B;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		Z = stoll(s);
		s1 = s.substr(0, s.size() / 2);
		s2 = s.substr(s.size() / 2, s.size() - 1);
		A = stoll(s1);
		//cout << A<<" ";
		B = stoll(s2);
		//cout << B;
		if (A*B == 0) { cout << "No" << endl; continue; }
		if (Z%(A*B)==0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
    return 0;
}

