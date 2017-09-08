#include<iostream>
#include<string.h>
using namespace std;
int main()
{
  char s[81]=""; 
  char c[80][80] = { "" };
  int N = 0,n1,n2,k=0;
  cin >> s;
  N = strlen(s);
  n1 = (N+2) / 3;
  n2 = n1 + (N+2) % 3;
  memset(c, ' ', sizeof(c));
  k = 0;
  for (int i = 0; i < n1; i++) 
    c[i][0] = s[k++];
  for (int i = 1; i < n2; i++) 
    c[n1 - 1][i] = s[k++];    
  for (int i = n1 - 2; i >= 0; i--) 
    c[i][n2 - 1] = s[k++];

  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) 
      cout << c[i][j];
    cout << endl;
  }
    return 0;
}