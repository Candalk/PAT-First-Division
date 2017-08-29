// 1005SpellItRight.cpp: 定义控制台应用程序的入口点。
//

//1005. Spell It Right(20)
//
//Given a non - negative integer N, your task is to compute the sum of all the digits of N, and 
//output every digit of the sum in English.
//
//Input Specification :
//
//Each input file contains one test case.Each case occupies one line which contains an N(<= 10^100).
//
//Output Specification :
//
//For each test case, output in one line the digits of the sum in English words.There must be one space
//between two consecutive words, but no extra space at the end of a line.
//
//Sample Input :
//12345
//Sample Output :
//one five
//解题思路：先输入字符串s，再把字符串中的每个字符分解出来，相加到sum中，再把sum用to_string()转换成字符串s，
//首先把每个数字的英文映射到一个一维数组num中，num[i]就是英文字母i，比如，num[0] = "zero".
//最后再把s从头到尾解析出字符串中的每个字符，每个字符等同于一个ASCII值，例如，‘0’的ASCII为49，但不能直接使用，
//分离出来的字符必须减去字符'0'才算是它真正的数字，然后映射到num中，输出出来即可。

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	string num[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int sum=0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		sum += s[i] - '0';
	s = to_string(sum);
	for (int i = 0; i < s.length(); i++) {
		if (i == 0)cout << num[s[i] - '0'];
		else cout<<" "<<num[s[i] - '0'];
	}
    return 0;
}

