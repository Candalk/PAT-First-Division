// 1051(Pop Sequence).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		stack<int> s;
		vector<int> v(N+1);
		bool flag = false;
		for (int j = 1; j <=N; j++)
			cin >> v[j];
		int current = 1;
		for (int j = 1; j <=N; j++) {
			s.push(j);
			if (s.size() > M)break;
			while (!s.empty() && s.top() == v[current]) {
				s.pop();
				current++;
			}
		}
		if (current == N + 1)flag = true;
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}

