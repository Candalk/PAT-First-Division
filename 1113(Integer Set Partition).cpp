#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> v[i];
	sort(v.begin()+1, v.end());
	int n1, n2, S1=0, S2=0;
	n1 = N /2;
	n2 = N- n1;
	cout << abs(n1 - n2);
	cout << " ";
	for (int i = 1; i <= n1; i++)
		S1 += v[i];
	for (int i = n1 + 1; i <= N; i++)
		S2 += v[i];
	cout << abs(S1 - S2);
    return 0;
}

