#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	set<int> s;
	string num;
	int N,all;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num; all = 0;
		for (int j = 0; j < num.size(); j++) {
			all += num[j] - '0';
		}
		s.insert(all);
	}
	cout << s.size()<<endl;
	for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
		if (i == s.begin())cout << *i;
		else cout << " " << *i;
	}
    return 0;
}

