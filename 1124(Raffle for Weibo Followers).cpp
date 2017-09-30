// 1124(Raffle for Weibo Followers).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int M, N, S, K = 1, num = 0;//K用于计算该第几个输出了
	string s;
	map<string, int> m;
	cin >> M >> N >> S;
	for (int i = 1; i <= M; i++) {
		cin >> s;
		if (i < S)continue;//如果当前输出的数还没到第一个输出的数，continue，不然会影响k的值，进而影响输出
		if (i == S) {//如果i==S,即第一个输出值，直接输出，并标记m[s]=1,表示已经输出，num的个数也要加1，然后跳过本次循环，
			cout << s << endl;
			m[s] = 1;
			num++;
			continue;
		}
			
		if(K == N) {//计算K的值正好等于N，则要判断是否输出过，
			if(m[s] == 0){//如果没有，直接输出s,并标记m[s]为1,num的个数也要加1，跳过本次循环，以免影响K的值
				cout << s << endl;
				K = 1;
				m[s] = 1;
				num++;
			}
			else continue;
			
		}
		else K++;
	}
	if (num == 0)cout << "Keep going...";//如果num=0,直接输出Keep going...
    return 0;
}

