#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node {
	int ID, best, score[4], rank[4];
};
int k;//用于标记要排哪一科的名次
bool cmp1(node a, node b) {
	return a.score[k] > b.score[k];
}
int main()
{
	int N, M, ID;
	char C[5] = "ACME";
	cin >> N >> M;
	vector<node> v(N);
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		cin >> v[i].ID >> v[i].score[1] >> v[i].score[2] >> v[i].score[3];
		v[i].score[0] = (v[i].score[1] + v[i].score[2] + v[i].score[3]) / 3;
		m[v[i].ID] = 1;
	}
	for (k = 0; k < 4; k++) {
		sort(v.begin(), v.end(), cmp1);
		for (int i = 0; i < N; i++) {
			if (i > 0 && v[i].score[k] == v[i - 1].score[k])
				v[i].rank[k] = v[i - 1].rank[k];
			else
				v[i].rank[k] = i;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> ID;
		if (m[ID]) {
			int i = 0;
			for (i = 0; i < N; i++)
				if (v[i].ID == ID) break;
			int best = 0;
			for (int j = 1; j < 4; j++)
				if (v[i].rank[best] > v[i].rank[j])best = j;
			printf("%d %c\n", v[i].rank[best]+1, C[best]);
		}
		else {
			printf("N/A\n");
		}
	}
	return 0;
}