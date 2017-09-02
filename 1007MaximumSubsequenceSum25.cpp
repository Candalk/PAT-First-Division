// 10071007MaximumSubsequenceSum25.cpp: 定义控制台应用程序的入口点。
//
// 1007. Maximum Subsequence Sum (25)
// Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
// Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
// Input Specification:
// Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.
// Output Specification:
// For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.
// Sample Input:
// 10
// -10 1 2 3 4 -5 -23 3 7 -21
// Sample Output:
// 10 1 4
// 解题思路：
// 第一步、先找到子序列的最大值
// 第二步、找到最大值以后，再返回找子序列的开口和结尾
// 代码：
#include<iostream>
using namespace std;
int main()
{
	int K,m[5001],n=0, sum = 0, N[10001] = { 0 },max=0;//sum用于求累加和，max用于存取最大值，
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> N[i];

	//找出最大值
	for (int i = 0; i < K; i++) {
		if (N[i] >= 0) {//子序列中第一个值必须大于等于0
			m[n++] = i;//将子序列第一个下标存入m数组中
			sum = 0; 
			for (int j = i; j < K; j++) {//第一个值为0以后以此相加，max用于存取最大值
				sum += N[j];
				if (max < sum)
					max = sum;
			}
		}
		else continue;
	}
	//cout <<"max= "<< max<<endl;
	int i=0,j=0,a,b,flag=1;//i,j用于存取子序列的第一个数的下标，j用于存取最后一个数字的下标，
						   //flag用于标记是否找到了i，j，找到以后停止
	for( a=0;a<K&&flag;a++){//a用于m数组的下标，从0开始
		sum = 0;
		for ( b = m[a];b<K; b++) {//开始相加，找到最大值后停止
			sum += N[b];
			if (sum == max) {
				i = m[a]; j = b;
				//cout << i << " " << j << endl;
				flag = 0;
				break;
			}
		}
		//cout <<"sum="<< sum << endl;
	}
	
	if (sum < 0)//按照题意，如果sum小于0，则最大值输出为0
		cout << "0 " << N[0] << " " << N[K - 1];
	else
		cout << max << " " <<N[i] << " "<<N[j] ;
    return 0;
}

