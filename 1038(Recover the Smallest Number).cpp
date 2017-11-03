/*
不是按照字典序排列就可以的，必须保证两个字符串构成的数字是最小的才行，
所以cmp函数写成return a + b < b + a;的形式，保证它排列按照能够组成的
最小数字的形式排列。
还有一个需要注意的是，如果都等于0，直接输出0
我当时错在了没有把结果合并起来输出，在除去0的时候出错了
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
	string A = a + b, B = b + a;
	return A < B;
}
int main()
{
	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++) 
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string s;
	for (int i = 0; i < N; i++) {
		s+= v[i];
	}
	while (s.length() != 0 && s[0] == '0')
		s.erase(s.begin());
	if (s.length() == 0)
		cout << "0";
	else cout << s;
    return 0;
}

