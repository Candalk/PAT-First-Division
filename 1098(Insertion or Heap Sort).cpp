// 1098(Insertion or Heap Sort).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v1, v2;
void print(vector<int> v) {
	for (int j = 1; j < v.size(); j++) {
		if (j == 1)
			printf("%d", v[j]);
		else
			printf(" %d", v[j]);
	}
}
void adjust(int low, int high) {
	int i = 1, j = i * 2;
	while (j <= high) {
		if (j + 1 <= high&&v2[j] < v2[j + 1])
			j = j + 1;
		if (v2[i] < v2[j]) {
			swap(v2[i], v2[j]);
			i = j;
			j = i * 2;
		}
		else {
			break;
		}
	}
}
int main()
{
	int N,i;
	scanf("%d", &N);
	v1.resize(N + 1), v2.resize(N + 1);
	for (int i = 1; i <= N; i++)
		scanf("%d", &v1[i]);
	for (int i = 1; i <= N; i++)
		scanf("%d", &v2[i]);
    i = 2;
	while (i <=N  && v2[i-1] <= v2[i])i++;//ע��߽����⣬ҪС�ڵ��ڲſ���
	int j = i ;
	while (i<=N && v2[i] == v1[i])i++;
	if (i == N+1) {
		printf("Insertion Sort\n");
		sort(v2.begin()+1, v2.begin()+ j+1 );
		print(v2);
	}
	else {
		printf("Heap Sort\n");
		i = N ;
		while (i >= 2 && v2[i] >= v2[i - 1])//����ҲҪע��߽����⣬�ǵü��ϵȺ�
			i--;
		swap(v2[1],v2[i]);
		adjust(1, i-1);
		print(v2);
	}
    return 0;
}

