/*
���ǰ����ֵ������оͿ��Եģ����뱣֤�����ַ������ɵ���������С�Ĳ��У�
����cmp����д��return a + b < b + a;����ʽ����֤�����а����ܹ���ɵ�
��С���ֵ���ʽ���С�
����һ����Ҫע����ǣ����������0��ֱ�����0
�ҵ�ʱ������û�аѽ���ϲ�����������ڳ�ȥ0��ʱ�������
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

