// 1104(Sum of Number Segments).cpp : 定义控制台应用程序的入口点。
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
	最初我选用的是遍历方法，但是效率太低，第三个第四个超时，
	根据总结我发现，第i个元素在排列中出现的次数为i*(N-i-1),
	题中i是从0开始计算的
	*/

	for (int i = 0; i < N; i++) {
		cin >> k;
		sum += k*(i + 1)*(N - i);
	}
	printf("%0.2f",sum);
    return 0;
}

