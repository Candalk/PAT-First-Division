/*
先把两个数组从大到小排序，
要加就加相乘大于0的
然后先从头开始乘，如果N[i],P[j]都大于0才相乘
如果出现N[i]<0或P[j]<0，停止
开始从从两个数组的末尾向前乘，如果N[i],P[j]都小于0才相乘
最后输出结果即可
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int NC, NP,total=0;
	cin >> NC;
	vector<int> N(NC);
	for (int i = 0; i < NC; i++)
		cin >> N[i];
	cin >> NP;
	vector<int> P(NP);
	for (int i = 0; i < NP; i++)
		cin >> P[i];
	sort(N.begin(), N.end(),cmp);
	sort(P.begin(), P.end(),cmp);
	int i = 0,j=0;
	while (N[i] > 0 && P[j] > 0) {
		total += N[i] * P[j];
		i++; j++;
	}
	i = N.size() - 1;
	j = P.size() - 1;
	while (i>=0&&j>=0&&N[i] < 0 && P[j] < 0) {
		total += N[i] * P[j];
		i--; j--;
	}
	printf("%d", total);
    return 0;
}

