// 1023HaveFunwithNumbers20.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,s1;
	int N1[10] = { 0 }, N2[10] = { 0 }, len = 0,  i, num1[21] = { 0 }, num2[21] = { 0 };
	cin >> s;
	for (i = 0; i < s.length(); i++) {
		N1[s[i] - '0']++;
		num1[i] = s[i] - '0';
	}
	len = s.length() - 1;
	int a = 0, b = 0;
	int j = 0;
	for (int i = len; i >= 0; i--) {
		a = (num1[i] * 2) % 10;
		b = (num1[i] * 2) / 10;
		//printf("a = %d , b = %d \n", a, b);
		num2[j] += a;
		num2[j + 1] += b;
		j++;
	}
	if (num1[0]< 5)j = j - 1;

	for (int i = j; i >= 0;i-- ) 
		N2[num2[i]]++;
	

	int flag = 1;
	for ( i = 0; i < 10; i++) 
		if (N1[i] != N2[i]) {
			flag = 0;
			break;
		}
					
	if(flag)
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
	for (int i = j; i >= 0; i--) 
		cout << num2[i];
	
    return 0;
}

