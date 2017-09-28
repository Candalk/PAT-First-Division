// 1100(Mars Numbers (20)).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string Lower[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" },
		Higher[12]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	string s;
	int N,K=0;
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++) {
		getline(cin,s);
		if (s[0] >= '0'&&s[0] <= '9') {//如果是数字
			K=stoi(s);//将string转化为int
			if (K / 13 != 0) {//这里要注意，如果是可以被13整除的数，后面不能输出tret，要特殊处理
				cout << Higher[K / 13 - 1];
				if(K % 13)
				cout<< " " << Lower[K % 13] << endl;
				else cout << endl;
			}
			else//如果K<13
				cout << Lower[K % 13]<<endl;
		}
		else {//如果火星文
			if (s == "tret") {//也是够奇葩的，别的火星文都是三个字符，就0时四个字符，特殊处理，如果是tret直接输出0
				cout << "0" << endl;
				continue;
			}
			string s1 = s.substr(0, 3);//获取第一个字符串
			string s2;
			if (s.length() > 3) //如果s字符串的的长度大于3，那么就是s里面有两个子字符串
				s2 = s.substr(4, s.length());//将第二个字符串获取到s2中
			if (s2 == "") {//如果没有第二个子字符串s2
				int i = 0;
				for (int i = 0; i < 13; i++) {//先遍历Lower数组，如果有直接输出i的大小
					if (Lower[i] == s1) {
						cout << i << endl;
						break;
					}
				}
				for (int i = 0; i < 12; i++) {//如果Lower中没有，在Higher中寻找，找到后输出(i+1)*13
					if (Higher[i] == s1) {
						cout << (i+1)*13 << endl;
						break;
					}
				}
			}
			else {//如果有第二个子字符串s2
				int sum = 0;//用sum记录转化后的地球数字的大小
				for (int i = 0; i < 12; i++) {//先处理第一个字符串，如果找到了	sum += (i+1) * 13;
					if (s1 == Higher[i]) {
						sum += (i+1) * 13;
						break;
					}
				}
				for (int i = 0; i < 13; i++) {//处理第二个字符串，如果找到了sum+=i
					if (s2 == Lower[i]) {
						sum += i;
						cout << sum << endl;
						break;
					}
				}
			}
		}
	}
	
	return 0;
}

