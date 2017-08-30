#include"stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N,H,M,S,early=86400,last=0,all;//一天总共86400秒
	string Sign_In, Sign_Out,name;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> name;
		scanf("%d:%d:%d", &H, &M, &S);
		all = H * 3600 + M * 60 + S;
		if (all < early) {
			early = all;
			Sign_In = name;
		}
		scanf("%d:%d:%d", &H, &M, &S);
		all = H * 3600 + M * 60 + S;
		if (all > last) {
			last = all;
			Sign_Out = name;
		}
	}
	cout << Sign_In << " " << Sign_Out;
    return 0;
}

