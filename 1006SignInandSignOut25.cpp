// 1006SignInandSignOut25.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int M;
struct node {
	string name;
	struct date {
		int H, M, S;
	}Sign_In,Sign_Out;//Sign_In表示进门时间。Sing_Out表示登出时间
}Sign[15];
bool cmp1(struct node A,struct node B) {
	if (A.Sign_In.H < B.Sign_In.H)return true;
	else if (A.Sign_In.H == B.Sign_In.H&&A.Sign_In.M < B.Sign_In.M)return true;
	else if (A.Sign_In.H == B.Sign_In.H&&A.Sign_In.M == B.Sign_In.M&&A.Sign_In.S < B.Sign_In.S)return true;
	return false;
}
bool cmp2(struct node A, struct node B) {
	if (A.Sign_Out.H > B.Sign_Out.H)return true;
	else if (A.Sign_Out.H == B.Sign_Out.H&&A.Sign_Out.M > B.Sign_Out.M)return true;
	else if (A.Sign_Out.H == B.Sign_Out.H&&A.Sign_Out.M == B.Sign_Out.M&&A.Sign_Out.S > B.Sign_Out.S)return true;
	return false;
}
int main()
{	
	char c;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> Sign[i].name;
		cin >> Sign[i].Sign_In.H >> c >> Sign[i].Sign_In.M >> c >> Sign[i].Sign_In.S;
		cin >> Sign[i].Sign_Out.H >> c >> Sign[i].Sign_Out.M >> c >> Sign[i].Sign_Out.S;	
	}	
	sort(Sign, Sign + M, cmp1);
	cout << Sign[0].name<<" ";
	sort(Sign, Sign + M, cmp2);
	cout << Sign[0].name;
    return 0;
}

