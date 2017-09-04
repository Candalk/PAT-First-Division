#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long m[256] = { 0 };
long long  ToInt(string s, long long index) {
	long long sum=0;
	for (int i = 0; i < s.length(); i++)
		sum =sum*index+m[s[i]];
	return sum;
}
long long MaxDigit(string s) {
	int max = -1;
	for (int i = 0; i < s.length(); i++)
		if (max<m[s[i]])
			max = m[s[i]];
	return max+1;
}
int cmp(string s,long long radix,long long t) {
	long long num = ToInt(s, radix);
	if (num > t||num<0)return 1;
	else if (num < t)return -1;
	else return 0;
}
long long BinarySearch(string s,long long left,long long right,long long t) {
	long long mid=9999;
	while (left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(s, mid, t);
		if (flag == 0) 
			return mid;
		else if (flag == -1)left = mid + 1;
		else right = mid - 1;
	}
		return -1;
}
int main()
{
	long long tag, radix,mid;
	string N1, N2;
	cin >> N1 >> N2;
	cin >> tag >> radix;
	for (int i = '0'; i <= '9'; i++)
		m[i] = i - '0';
	for (int i = 'a'; i <= 'z'; i++)
		m[i] = i - 'a'+10;

	if (tag == 2)swap(N1, N2);
	
	long long t = ToInt(N1, radix);
	long long low = MaxDigit(N2);
	long long high = max(low,t) + 1;
	long long ans = BinarySearch(N2, low, high, t);
	if (ans==-1)cout << "Impossible";
	else printf("%lld", ans);
    return 0;
}

