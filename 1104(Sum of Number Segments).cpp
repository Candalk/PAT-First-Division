// 1104(Sum of Number Segments).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int N;
	double sum = 0,k;
	cin >> N;
	/*
	�����ѡ�õ��Ǳ�������������Ч��̫�ͣ����������ĸ���ʱ��
	�����ܽ��ҷ��֣���i��Ԫ���������г��ֵĴ���Ϊi*(N-i-1),
	����i�Ǵ�0��ʼ�����
	*/

	for (int i = 0; i < N; i++) {
		cin >> k;
		sum += k*(i + 1)*(N - i);
	}
	printf("%0.2f",sum);
    return 0;
}

