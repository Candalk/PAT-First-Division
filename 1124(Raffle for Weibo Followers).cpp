// 1124(Raffle for Weibo Followers).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int M, N, S, K = 1, num = 0;//K���ڼ���õڼ��������
	string s;
	map<string, int> m;
	cin >> M >> N >> S;
	for (int i = 1; i <= M; i++) {
		cin >> s;
		if (i < S)continue;//�����ǰ���������û����һ�����������continue����Ȼ��Ӱ��k��ֵ������Ӱ�����
		if (i == S) {//���i==S,����һ�����ֵ��ֱ������������m[s]=1,��ʾ�Ѿ������num�ĸ���ҲҪ��1��Ȼ����������ѭ����
			cout << s << endl;
			m[s] = 1;
			num++;
			continue;
		}
			
		if(K == N) {//����K��ֵ���õ���N����Ҫ�ж��Ƿ��������
			if(m[s] == 0){//���û�У�ֱ�����s,�����m[s]Ϊ1,num�ĸ���ҲҪ��1����������ѭ��������Ӱ��K��ֵ
				cout << s << endl;
				K = 1;
				m[s] = 1;
				num++;
			}
			else continue;
			
		}
		else K++;
	}
	if (num == 0)cout << "Keep going...";//���num=0,ֱ�����Keep going...
    return 0;
}

