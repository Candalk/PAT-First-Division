// 1017(Queueing at Bank).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int earlyTime = 8 * 60 * 60,lastTime=17*60*60;
struct node {
	int time,process;
}Temp;
bool cmp(node a, node b) {
	return a.time < b.time;
}
int main()
{
	int N, K,H,M,S,Process,sum=0;
	int window[101];
	fill(window, window + 101, earlyTime);
	cin >> N >> K;
	
	vector<node> v;
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d", &H, &M, &S, &Process);
		 Temp.time = H * 60 * 60 + M * 60 + S;
		 Temp.process = Process;
		if (Temp.time > lastTime) 
			continue;
			
		if (Temp.process > 60)
			Temp.process = 60;

		Temp.process = Temp.process * 60;
		v.push_back(Temp);
		
	}
	sort(v.begin(), v.end(),cmp);

	
	for (int i = 0; i < v.size(); i++) {
		//找到等待时间最短的窗口
		int min = 0;
		for (int j = 1; j < K; j++)
			if (window[j] < window[min]) 
				min = j;

		/*
		两种情况：
		1、如果去了，前面的人还没处理完毕
		2、如果去了，前面的人没人，直接办理自己的事
		*/
		if (window[min] > v[i].time) {//如果来了需要等待
			sum += window[min] - v[i].time;
			
		}
		else if (window[min] <= v[i].time) {
			window[min] = v[i].time;
		}
		window[min] += v[i].process;
	}
	double fin = sum*1.0 / (60 * v.size());
	if (v.size() == 0)
		printf("0.0");
	else
		printf("%0.1f", fin);
    return 0;
}

