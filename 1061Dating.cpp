#include<string>
using namespace std;
int main()
{
	string s1, s2, week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	cin >> s1 >> s2;
	int j = 0, DAY, HH, MM;
	for (int i = 0; i < s1.length() && i < s2.length(); i++) {
		if (j == 0 && s1[i] == s2[i] && s1[i] >= 'A'&&s1[i] <= 'G') {
			cout << week[s1[i] - 'A'] << " ";
			j++;
		}
		else if (j == 1 && s1[i] == s2[i]) {
			if (s1[i] <= '9'&&s1[i] >= '0') {
				printf("%02d", s1[i] - '0'); break;
			}
			else if (s1[i] <= 'N'&&s1[i] >= 'A') { 
				printf("%02d", s1[i] - 'A' + 10); break; }
			
		}
	}
	printf(":");
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length() && i < s2.length(); i++) {
		if ((s1[i] >= 'a'&&s1[i] <= 'z') || (s1[i] >= 'A'&&s1[i] <= 'Z'))
			if (s1[i] == s2[i]) {
				printf("%02d", i);
				break;
			}
	}
	return 0;
}

