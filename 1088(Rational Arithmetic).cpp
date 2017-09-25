#include"stdafx.h"
#include<iostream>
using namespace std;
long long int a1, b1,a2,b2;
int GCD(long long int a, long long int b) {
	if (a%b == 0)
		return b;
	return GCD(b, a%b);
}
int print(long long int a, long long int b) {
	int k = 1;
	if (b == 0) {//�������Ϊ0��ֱ�����Inf
		printf("Inf");
		return 0;
	}
	if (a == 0) {//�������Ϊ0��ֱ�����0
		printf("0");
		return 0;
	}
	if (b < 0) {//�÷�ĸ��С��0
		a = -a;
		b = -b;
	}
	if (a < 0) {//k���ڱ�Ƿ�������
		a = -a;
		k = -1;
	}
	long long int gcd = GCD(a, b);
	a = a / gcd;
	b = b / gcd;
	if (a < b&&k>0) {
		printf("%lld/%lld",a,b);
	}else if (a < b&&k < 0) {
		printf("(%lld/%lld)", -a, b);
	}else if (a%b == 0 && k > 0) {
		printf("%lld", a / b);
	}else if (a%b == 0 && k < 0) {
		printf("(%lld)", -a / b);
	}else if (a > b&&k > 0) {
		printf("%lld %lld/%lld", a / b, a%b, b);
	}else if (a > b&&k < 0) {
		printf("(%lld %lld/%lld)", -a / b, a%b, b);
	}
	return 0;
}
int Add( ) {
	long long int  a, b;
	b = b1*b2;
	a = a1*b2 + a2*b1;
	print(a,b);
	return 0;
}
int Sub( ) {
	long long int  a, b;
	b = b1*b2;
	a = a1*b2 - a2*b1;
	print(a, b);
	return 0;
}
int Multi( ) {
	long long int  a, b;
	b = b1*b2;
	a = a1*a2;
	print(a, b);
	return 0;
}
int Divi( ) {
	long long int  a, b;
	a = a1*b2;
	b = a2*b1;
	print(a, b);
	return 0;
}
int main()
{
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	print(a1,b1); cout << " + "; print(a2,b2); cout << " = "; Add( ); cout << endl;
	print(a1,b1); cout << " - "; print(a2,b2); cout << " = "; Sub( ); cout << endl;
	print(a1,b1); cout << " * "; print(a2,b2); cout << " = "; Multi( ); cout << endl;
	print(a1,b1); cout << " / "; print(a2,b2); cout << " = "; Divi( ); cout << endl;
	return 0;
}