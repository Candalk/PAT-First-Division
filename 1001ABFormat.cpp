// 1001ABFormat.cpp: 定义控制台应用程序的入口点。
//

//1001. A + B Format(20)
//
//Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas(unless there are less than four digits).
//
//Input
//
//Each input file contains one test case.Each case contains a pair of integers a and b where - 1000000 <= a, b <= 1000000. The numbers are separated by a space.
//
//Output
//
//For each test case, you should output the sum of a and b in one line.The sum must be written in the standard format.
//
//Sample Input
//- 1000000 9
//Sample Output
//- 999, 991
//
//解析：题意的大致意思就是输入a,b(-1000000 <= a, b <= 1000000)两个数，并求两个整数的和，
//但是输出时要求四位数及四位数以上的数字，从右到左，三个一组用逗号隔离.
//解题思路：先计算出结果，再转换成字符串，然后依次输出，每次输出后都要判断该字符串与最后
//一个字符串的距离，如果而这距离不等于0且是三的倍数，输出逗号

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a, b,sum=0;
	string s;
	cin >> a >> b;
	sum = a + b;
	if (sum < 0){
		cout << "-";
		sum = -sum;
	}
	s = to_string(sum);//将结果转换成字符串
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		if ((s.size()!=i+1)&&(s.size() - 1 - i) % 3 == 0) //如果不是最后一个字符串，且距离
			cout << ",";								 //最后一个字符串有三个字符，输出逗号
	}
    return 0;
}
