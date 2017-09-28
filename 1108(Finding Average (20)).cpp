#include<iostream>
#include<string>
using namespace std;
bool islegal(string s) {
	int i = 0,decimal=0;
	if (s[0] == '-')//如果第一个是负号，从下一个字符开始统计
		i++;
	if (s[i] == '.')return false;
	while (i < s.length()) {
		if (s[i] == '.')decimal++;//decimal用于统计小数点的个数
		if (decimal >= 2)return false;//如果小数点的个数大于等于2，非法，返回false
		if ((s[i] > '9' || s[i] < '0') && s[i] != '.')return false;//如果里面有非数字和小数点的字符，返回false
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
		if (islegal(s)) {//先判断是不是一个合法的数
			for (int i = 0; i < s.length(); i++) //计算小数点的个数，如果大于2，flag=0
				if (s[i] == '.') 
					if (s.length() - i-1 > 2)flag = 0;
				
			X = stod(s);//转换成double数据
			if (X < -1000 || X>1000)
				flag = 0;

		}else//如果不是一个合法的数据，直接flag=0
			flag = 0;

		if(flag==0)//如果不是一个合法的数据
			printf("ERROR: %s is not a legal number\n", s.c_str());
		else { //如果是一个合法的数据，num的个数加1，Y用于统计合法数的和，Y加上X，
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

