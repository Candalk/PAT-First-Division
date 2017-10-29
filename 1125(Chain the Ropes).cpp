#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	double sum = v[0];
	for (int i = 1; i < N; i++) {
		sum = (sum + v[i])*1.0 / 2;
	}
	
	printf("%d", int(sum));
    return 0;
}

