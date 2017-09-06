#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	long long N, b, temp, i = 0, s[65] = { 0 };
	
	cin >> N >> b;
	if (N == 0) {
		cout << "Yes"<<endl;
		cout << "0" << endl;
		return 0;
	}
	temp = N;
	while (temp) {
		s[i] = temp%b;
		temp = temp / b;
		i++;
	}
	bool flag = true;
	for (int j = 0; j < i/2; j++) {
		if (s[j] != s[i - j - 1]) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	
	for (int j = i-1; j >=0; j--)
		if (j == i-1)cout << s[j];
		else cout << " " << s[j];
	
    return 0;
}

