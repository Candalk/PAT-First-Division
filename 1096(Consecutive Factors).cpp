// 1096(Consecutive Factors).cpp : �������̨Ӧ�ó������ڵ㡣
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
	for (int len = 12; len >= 1; len--) {//����
		for (int start = 2; start <=max; start++) {//��ʼ����
			long long int ans = 1;//���ڼ�¼�������������ĳ˻�
			for (int k = start; k-start <= len-1; k++) {//���ݳ����Լ���ʼ�����֣��Դ˳�ȡ
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

