/*
�Ȱ���������Ӵ�С����
Ҫ�Ӿͼ���˴���0��
Ȼ���ȴ�ͷ��ʼ�ˣ����N[i],P[j]������0�����
�������N[i]<0��P[j]<0��ֹͣ
��ʼ�Ӵ����������ĩβ��ǰ�ˣ����N[i],P[j]��С��0�����
�������������
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

