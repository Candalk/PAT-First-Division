// 1077(Kuchiguse (20))2.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	string s,ans;
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++) {
		getline(cin,s);
		reverse(s.begin(), s.end());
		if (i == 0)
			ans = s;
		else {
			int min = ans.length() < s.length()?ans.length(): s.length();
			for (int j = 0; j < min; j++) {
				if (s[j] != ans[j]) {
					ans = ans.substr(0,j);
					break;
				}
			}
		}

	}
	reverse(ans.begin(), ans.end());
	if (ans.length() == 0)ans = "nai";
	cout << ans;
    return 0;
}

