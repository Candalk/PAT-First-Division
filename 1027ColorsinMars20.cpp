#include<iostream>
using namespace std;
int main()
{
	char radix[14] = "0123456789ABC";
	char c[7] = "";
	int a;	
	for (int i = 0; i < 3; i++) {
		cin >> a;
		c[2*i] = radix[a / 13];
		c[2 * i + 1] = radix[a % 13];
	}
	cout << "#";
	cout << c;
    return 0;
}

