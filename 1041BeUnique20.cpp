#include<iostream>
using namespace std;
int main()
{
	int mark[10001] = { 0 }, N, k[100001] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> k[i];
		mark[k[i]]++;
	}
	for (int i = 0; i < 100001; i++) {
		if (mark[k[i]] == 1) {
			cout << k[i];
			return 0;
		}
	}
	cout << "None";
    return 0;
}

