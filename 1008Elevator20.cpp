// 1008Elevator20.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace std;
int main()
{
	int N,a,tmp=0,sum=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a - tmp > 0)
			sum += (a - tmp) * 6;
		else
			sum += (tmp - a) * 4;
		tmp = a;
	}
	sum += 5 * N;
	cout << sum;
    return 0;
}

