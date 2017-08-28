// 1002ABforPolynomials25.cpp: 定义控制台应用程序的入口点。
////
//1002. A+B for Polynomials (25) 
//
//
//This time, you are supposed to find A + B where A and B are two polynomials.
//
// Input 
//
//Each input file contains one test case.Each case occupies 2 lines, and each line contains the information of a polynomial : K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi(i = 1, 2, ..., K) are the exponents and coefficients, respectively.It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <= 1000.
//
// Output 
//
//	For each test case you should output the sum of A and B in one line, with the same format as the input.Notice that there must be NO extra space at the end of each line.Please be accurate to 1 decimal place.
//
//	Sample Input
//
//	2 1 2.4 0 3.2
//	2 2 1.5 1 0.5
//
//	Sample Output
//
//	3 2 1.5 1 2.9 0 3.2
//
//	Suggest Input 1 
//
//	2 4 2.3 2 2.3
//	2 3 1.2 1 1.2
//
//	Output
//
//	4 4 2.3 3 1.2 2 2.3 1 1.2
//
//	Suggest Input 2 
//
//	2 2 1.5 1 1.2
//	2 2 - 1.5 1 - 1.2
//
//	Output
//
//	0
//
//
//	注意点：系数为0后不输出。

#include "stdafx.h"
#include<iostream>
using namespace std;
struct node {
	int N;
	float a;
}A[10],B[10],sum[21];
int main()
{
	int Ka,Kb;//Ka表示A式元素的个数，Kb表示B式元素的个数
	cin >> Ka;
	for (int i = 0; i < Ka; i++) 
		cin >> A[i].N >> A[i].a;

	cin >> Kb;
	for (int i = 0; i < Kb; i++)
		cin >> B[i].N >> B[i].a;

	int i = 0, j = 0, k = 0;
	while (i < Ka || j < Kb) {
		if (i == Ka ) {//如果A式已显示完毕，则开始显示B式
			sum[k].N = B[j].N;
			sum[k].a = B[j].a;
			k++; j++;
			//cout << sum[k - 1].N << " " << sum[k - 1].a << endl;
			continue;
		}
		else if (j == Kb) {//如果B式已显示完毕，则开始显示A式
			sum[k].N = A[i].N;
			sum[k].a = A[i].a;
			k++; i++;
			//cout << sum[k - 1].N << " " << sum[k - 1].a << endl;
			continue;
		}

		if (A[i].N == B[j].N) {//如果A式的某一项的指数与B式的指数相同，则二者系数相加到sum中
			sum[k].N = A[i].N;
			sum[k].a = A[i].a + B[j].a;
			k++; i++; j++;
			//printf("A[%d].N == B[%d].N \n", i, j);
		}
		else {
			if (A[i].N > B[j].N) {//如果A式的某一项的指数大于B式的指数
				sum[k].N = A[i].N;
				sum[k].a = A[i].a;
				k++; i++;

			}
			else {//如果A式的某一项的指数小于B式的指数
				sum[k].N = B[j].N;
				sum[k].a = B[j].a;
				k++; j++;
			}
		}
		if (sum[k-1].a == 0) k--;//如果系数为0，删去
		//cout << sum[k - 1].N << " " << sum[k - 1].a << endl;
	}
	cout << k;
	for (int i = 0; i < k; i++)
			printf(" %d %0.1f", sum[i].N, sum[i].a);
    return 0;
}

