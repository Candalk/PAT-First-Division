#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int min(char c[5]) {
	int sum = 0;
	for (int i = 0; i<4; i++)
		sum = sum * 10 + c[i] - '0';
	return sum;
}
int max(char c[5]) {
	int sum = 0;
	for (int i = 3; i >= 0; i--)
		sum = sum * 10 + c[i] - '0';
	return sum;
}
void tostr(int n, char c[5]) {
	int i = 3;
	while (i >= 0) {
		c[i--] = n % 10 + '0';
		n = n / 10;
	}

}
int main() {

	char c[5] = "";
	int f = 999999, num;
	cin >> num;
	tostr(num, c);
	while (f != 6174 || f != 0) {
		sort(c, c + 4);
		f = max(c) - min(c);
		printf("%0.4d - %0.4d = %0.4d\n", max(c), min(c), f);
		if (f == 6174 || f == 0)return 0;
		tostr(f, c);
	}
}