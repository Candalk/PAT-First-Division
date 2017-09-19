// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int Point=2,i,index;
	string S,s1,s2;
	cin >> S;
	for (i = 1; i < S.length(); i++)
		if (S[i] == 'E')break;
	s1 = S.substr(1, i-1);
	s2 = S.substr(i + 1, S.length());
	index = atoi(s2.c_str());
	/*cout << "s1 = " << s1<<endl;
	cout << "s2 = " << s2<<endl;
	cout << "index = " << index << endl;*/
	if (S[0] == '-')cout << '-';
	if (index < 0) {
		cout << "0.";
		for (int j = 0; j < -1 - index; j++)
			cout << 0;
		for (int j = 0; j < s1.length(); j++) {
			if (s1[j] == '.')continue;
			else cout << s1[j];
		}
	}
	else {
		Point += index;
		//cout << Point;
		for (int j = 0; j < s1.length()||j<Point; j++) {
			//printf("j = %d,s1[j] = %c\n", j, s1[j]);
			if (j >= s1.length())cout << "0";
			else if (s1[j] != Point&&s1[j] == '.') continue;
			else if (Point == j) cout << "." << s1[j];
			else cout << s1[j];
		}
	}
	
    return 0;
}

