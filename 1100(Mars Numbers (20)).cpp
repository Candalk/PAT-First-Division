// 1100(Mars Numbers (20)).cpp : �������̨Ӧ�ó������ڵ㡣
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
		if (s[0] >= '0'&&s[0] <= '9') {//���������
			K=stoi(s);//��stringת��Ϊint
			if (K / 13 != 0) {//����Ҫע�⣬����ǿ��Ա�13�������������治�����tret��Ҫ���⴦��
				cout << Higher[K / 13 - 1];
				if(K % 13)
				cout<< " " << Lower[K % 13] << endl;
				else cout << endl;
			}
			else//���K<13
				cout << Lower[K % 13]<<endl;
		}
		else {//���������
			if (s == "tret") {//Ҳ�ǹ�����ģ���Ļ����Ķ��������ַ�����0ʱ�ĸ��ַ������⴦�������tretֱ�����0
				cout << "0" << endl;
				continue;
			}
			string s1 = s.substr(0, 3);//��ȡ��һ���ַ���
			string s2;
			if (s.length() > 3) //���s�ַ����ĵĳ��ȴ���3����ô����s�������������ַ���
				s2 = s.substr(4, s.length());//���ڶ����ַ�����ȡ��s2��
			if (s2 == "") {//���û�еڶ������ַ���s2
				int i = 0;
				for (int i = 0; i < 13; i++) {//�ȱ���Lower���飬�����ֱ�����i�Ĵ�С
					if (Lower[i] == s1) {
						cout << i << endl;
						break;
					}
				}
				for (int i = 0; i < 12; i++) {//���Lower��û�У���Higher��Ѱ�ң��ҵ������(i+1)*13
					if (Higher[i] == s1) {
						cout << (i+1)*13 << endl;
						break;
					}
				}
			}
			else {//����еڶ������ַ���s2
				int sum = 0;//��sum��¼ת����ĵ������ֵĴ�С
				for (int i = 0; i < 12; i++) {//�ȴ����һ���ַ���������ҵ���	sum += (i+1) * 13;
					if (s1 == Higher[i]) {
						sum += (i+1) * 13;
						break;
					}
				}
				for (int i = 0; i < 13; i++) {//����ڶ����ַ���������ҵ���sum+=i
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

