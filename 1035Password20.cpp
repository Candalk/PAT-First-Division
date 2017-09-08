#include<iostream>
#include<string>
using namespace std;
struct node {
	string name, pwd;
}PAT[1001];
int main()
{
	int flag = 0,M=0,N,num=0;
	string name = "", pwd = "";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name;
		cin >> pwd;
		flag = 1;
		for (int j = 0; j < pwd.length(); j++) {
			if (pwd[j] == '1' || pwd[j] == '0' || pwd[j] == 'l' || pwd[j] == 'O')
				flag = 0;
		}
		if (flag == 0) {	
			PAT[M].name = name;
			PAT[M].pwd = pwd;
			M++;
		}
		else num++;
	}
	if (M==0&&num == 1){
		cout << "There is 1 account and no account is modified";
		return 0;
	}
	else if (M == 0 && num >= 2) { 
		printf("There are %d accounts and no account is modified", num); 
		return 0;
	}
	
	cout << M << endl;
	for (int i = 0; i < M; i++) {
		cout << PAT[i].name<<" ";
		for (int j = 0; j < PAT[i].pwd.length(); j++) {
			if (PAT[i].pwd[j] == '1')cout << '@';
			else if (PAT[i].pwd[j] == '0')cout << '%';
			else if (PAT[i].pwd[j] == 'l')cout << 'L';
			else if (PAT[i].pwd[j] == 'O')cout << 'o';
			else cout << PAT[i].pwd[j];
		}
		cout << endl;
	}
	
	return 0;
}

