#include<iostream>
#include<string>
using namespace std;
bool islegal(string s) {
	int i = 0,decimal=0;
	if (s[0] == '-')//�����һ���Ǹ��ţ�����һ���ַ���ʼͳ��
		i++;
	if (s[i] == '.')return false;
	while (i < s.length()) {
		if (s[i] == '.')decimal++;//decimal����ͳ��С����ĸ���
		if (decimal >= 2)return false;//���С����ĸ������ڵ���2���Ƿ�������false
		if ((s[i] > '9' || s[i] < '0') && s[i] != '.')return false;//��������з����ֺ�С������ַ�������false
		i++;
	}
	return true;
}
int main()
{
	int N,num=0;
	double X=0, Y=0;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		int flag = 1;
		//cout << islegal(s) << endl;
		if (islegal(s)) {//���ж��ǲ���һ���Ϸ�����
			for (int i = 0; i < s.length(); i++) //����С����ĸ������������2��flag=0
				if (s[i] == '.') 
					if (s.length() - i-1 > 2)flag = 0;
				
			X = stod(s);//ת����double����
			if (X < -1000 || X>1000)
				flag = 0;

		}else//�������һ���Ϸ������ݣ�ֱ��flag=0
			flag = 0;

		if(flag==0)//�������һ���Ϸ�������
			printf("ERROR: %s is not a legal number\n", s.c_str());
		else { //�����һ���Ϸ������ݣ�num�ĸ�����1��Y����ͳ�ƺϷ����ĺͣ�Y����X��
			num++;
			Y += X;
		}
	}

	if (num == 0) {
		printf("The average of 0 numbers is Undefined");
	}
	else if (num == 1)
		printf("The average of 1 number is %0.2lf", Y);
	else
		printf("The average of %d numbers is %0.2lf",num, Y/num*1.0);
	
    return 0;
}

