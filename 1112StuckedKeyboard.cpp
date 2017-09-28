// 1112StuckedKeyboard.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m[128] = { 0 };//1表示可能是坏掉的键，-1一定不是坏掉的键，0表示不确定是不是坏的
	int k,num=0;
	int flag[128] = { 0 };//在输出是标识是否输出过
	string s;
	cin >> k;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
			num++;
			if (i+1<s.length()&&s[i + 1] == s[i])//如果下一个字符和当前字符相等
				continue;
			else {//如果下一个字符和当前字符不相等，那就先判断当前字符的个数，
				  //如果为k的倍数，那就可能坏的键
				if (num%k == 0&& m[s[i]]!= -1)
					m[s[i]] = 1;
				else
					m[s[i]] = -1;
				num = 0;
			}
	}
	for (int i = 0; i < s.length(); i++){
		if (m[s[i]]==1&&flag[s[i]]==0) {
			if (i != '_')
				printf("%c", s[i]);
			else
				printf(" ");
			flag[s[i]] = 1;
		}
	}
	cout << endl;
	for (int i = 0; i < s.length();) {
		if (m[s[i]]!=1)
			cout << s[i++];
		else{
			cout << s[i];
			i = i + k;
		}
			
	}
    return 0;
}

