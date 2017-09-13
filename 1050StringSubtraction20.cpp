#include<iostream>
#include<string>
using namespace std;

int main()
{
	int  flag[128] = {0};
	string S1 = "",S2="";
	getline(cin, S1);
	getline(cin, S2);
	for (int i = 0; i < S2.length(); i++)
		flag[S2[i]] = 1;
	for (int i = 0; i < S1.length(); i++)
		if (flag[S1[i]] == 0)cout << S1[i];
    return 0;
}

