// 1092(To Buy or Not to Buy).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	int a1[128] = { 0 }, a2[128] = { 0 },Y=0,N=0,flag=1;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) 
		a1[s1[i]]++;
	for (int i = 0; i < s2.length(); i++)
		a2[s2[i]]++;
	for (int i = 0; i < 128; i++) {
		//if(a1[i]!=0||a2[i]!=0)
			//printf("i = %c,a1[i] = %d , a2[i] = %d\n", i, a1[i], a2[i]);
		if (a1[i] >= a2[i]) 
			continue;
			
		else if(a2[i]!=0&& a1[i]<a2[i]){
			//printf("N = %d\n", N);
			N+= a2[i] - a1[i];
			flag = 0;
		}
	}
	if (flag)printf("Yes %d", s1.length()-s2.length());
	else printf("No %d", N);
    return 0;
}

