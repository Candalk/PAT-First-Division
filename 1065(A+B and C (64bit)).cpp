// 1065(A+B and C (64bit)).cpp : �������̨Ӧ�ó������ڵ㡣
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
		if (A > 0 && B > 0&&s<0)  flag = 1;//A��B��ֵ������0������A+BС��0��˵��Խ���ˣ�����A+B>C
		else if (A < 0 && B < 0 && s>=0) flag = 0;//A��B��ֵ��С��0������A+B����0��˵��Խ���ˣ�����A+B<C
		else if (s > C)flag = 1;//���A,B����һ���������Ų�һ����ֱ���ж�A+B�Ĵ�С
		else flag = 0;

		if(flag)
			printf("Case #%d: true\n", i + 1);
		else
			printf("Case #%d: false\n", i + 1);
	}
	
    return 0;
}

