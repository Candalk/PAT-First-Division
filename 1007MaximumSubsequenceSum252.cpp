// 1007MaximumSubsequenceSum252.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int K, N[10001], Left, Right, tempindex=0,sum = 0, max = -1,flag=0;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N[i];
		if (N[i] >= 0)
			flag = 1;
		sum += N[i];
		if (sum > max) {
			Right = i;
			max = sum;
			Left = tempindex;
		}
		else if (sum < 0) {
			sum = 0;
			tempindex = i + 1;
		}
	}
	if (flag)
		cout << max << " " << N[Left] << " " << N[Right];
	else cout << "0 " << N[0] << " " << N[K - 1];
    return 0;
}

