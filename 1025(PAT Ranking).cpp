// 1025(PAT Ranking).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	string reg_num;
	int location_num, local_rank,Grade,final_rank;
};
bool cmp(node a, node b) {
	if (a.Grade != b.Grade)
		return a.Grade > b.Grade;
	else 
		return a.reg_num < b.reg_num;
}
int main()
{
	int N, K,Grade;
	string num;
	cin >> N;

	vector<node> sum;
	for (int i = 1; i <=N; i++) {
		cin >> K;
		vector<node> v(K );

		for (int j = 0; j < K; j++) {
			cin >> num >> Grade;
			v[j].reg_num = num;
			v[j].location_num = i;
			v[j].Grade = Grade;
			
		}

		sort(v.begin(), v.end(),cmp);
		for (int j = 0; j < K; j++) {
			if (j>0&&v[j].Grade == v[j - 1].Grade) {
				v[j].local_rank = v[j-1].local_rank;
			}else
				v[j].local_rank = j + 1;	
			sum.push_back(v[j]);
		}
	}

	sort(sum.begin(), sum.end(),cmp);


	cout << sum.size() << endl;
	for (int i = 0; i < sum.size(); i++) {
		if (i > 0 && sum[i].Grade == sum[i - 1].Grade)
			sum[i].final_rank = sum[i - 1].final_rank;
		else
			sum[i].final_rank = i + 1;
			printf("%s %d %d %d\n", sum[i].reg_num.c_str(), sum[i].final_rank, sum[i].location_num, sum[i].local_rank);
	}
    return 0;
}

