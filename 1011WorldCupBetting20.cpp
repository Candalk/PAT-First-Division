// 1011WorldCupBetting20.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	double f[3];
	char c[4] = { 'W','T','L'};
	double sum = 1.0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) 
			cin >> f[j];
		int m = 0;
		for (int j = 1; j < 3; j++)
			if (f[j] > f[m])m = j;

		//cout << "m = " << m << endl;
		cout << c[m]<<" ";
		sum *= f[m];
	}
	printf("%.2lf", 2.0 * (sum*0.65-1.0));
    return 0;
}

