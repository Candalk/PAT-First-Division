// 1096(Consecutive Factors).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int N,max;
	cin >> N;
	max = sqrt(N);
	for (int len = 12; len >= 1; len--) {//长度
		for (int start = 2; start <=max; start++) {//开始的数
			long long int ans = 1;//用于记录几个连续的数的乘积
			for (int k = start; k-start <= len-1; k++) {//根据长度以及开始的数字，以此乘取
				ans *= k;
			}
			if (N%ans == 0) {
				printf("%d\n%d", len,start);
				for (int k = start+1; k-start <= len-1; k++) {
					printf("*%d", k);
				}
				return 0;
			}
		}
	}
	printf("1\n%d",N);
    return 0;
}

