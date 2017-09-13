#include<iostream>
#include<map>
using namespace std;
int main()
{
	int M, N, half,s;
	map<int, int> m;
	cin >> M >> N;
	half = M*N /2;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> s;
			m[s]++;
			if (m[s] > half) {
				cout << s;
				return 0;
			}
		}
	}
	return 0;
}