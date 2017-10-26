// 1065(A+B and C (64bit)).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int N;
	long long int A, B, C;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int flag = 1;
		cin >> A >> B >> C;
		long long int s = A + B;
		if (A > 0 && B > 0&&s<0)  flag = 1;//A，B的值都大于0，但是A+B小于0，说明越界了，所以A+B>C
		else if (A < 0 && B < 0 && s>=0) flag = 0;//A，B的值都小于0，但是A+B大于0，说明越界了，所以A+B<C
		else if (s > C)flag = 1;//如果A,B二者一个正负符号不一样，直接判断A+B的大小
		else flag = 0;

		if(flag)
			printf("Case #%d: true\n", i + 1);
		else
			printf("Case #%d: false\n", i + 1);
	}
	
    return 0;
}

