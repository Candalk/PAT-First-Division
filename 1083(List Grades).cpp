#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	char name[11], ID[11];
	int grade;
};
bool cmp(node a, node b) {
	return a.grade > b.grade;
}
int main()
{
	
	int N,Low,High;
	scanf("%d", &N);
	vector<node> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", v[i].name,v[i].ID,&v[i].grade);
	}
	scanf("%d %d", &Low, &High);
	sort(v.begin(), v.end(), cmp);
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].grade >= Low&&v[i].grade <= High) {
			printf("%s %s\n", v[i].name, v[i].ID);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("NONE");
	}
    return 0;
}

