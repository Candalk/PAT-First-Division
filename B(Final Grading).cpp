// B(Final Grading).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iterator>
#include<map>
using namespace std;
struct node {
	string ID;
	int GPout=0,Gout=0;
	int Gp=-1,Gmid=-1, Gfinal=-1, G=-1;
};
bool cmp(node a,node b) {
	if (a.G != b.G)return a.G > b.G;
	else return a.ID < b.ID;
}
int main()
{
	int P, M, N;
	cin >> P >> M >> N;
	map<string, node> m;
	
	for (int i = 0; i < P; i++) {
		string ID;
		int GP;
		cin >> ID >> GP;
		m[ID].ID = ID;
		m[ID].Gp = GP;
		if (GP < 200)m[ID].GPout = 0;
		else m[ID].GPout = 1;
	}

	for (int i = 0; i < M; i++) {
		string ID;
		int Gmid;
		cin >> ID >> Gmid;
		m[ID].ID = ID;
		m[ID].Gmid = Gmid;
	}
	for (int i = 0; i < N; i++) {
		string ID;
		int Gfinal;
		cin >> ID >> Gfinal;
		m[ID].ID = ID;
		m[ID].Gfinal = Gfinal;
		if (m[ID].Gmid > m[ID].Gfinal) {
			double d = (m[ID].Gmid*1.0*0.4 + m[ID].Gfinal*1.0*0.6)+0.5;
			//cout << ID<<"d = " << d << endl;
			m[ID].G = (int)d;
		}
			
		else m[ID].G = m[ID].Gfinal;
		if (m[ID].G >= 60 && m[ID].G <= 100)m[ID].Gout = 1;
		else m[ID].Gout = 0;
	}

	vector<node> v;
	for (map<string, node>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second.GPout == 1 && it->second.Gout == 1) {
			//printf("%s %d %d %d %d\n", it->first.c_str(), it->second.Gp, it->second.Gmid, it->second.Gfinal, it->second.G);
			node temp;
			v.push_back(it->second);
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		printf("%s %d %d %d %d\n", v[i].ID.c_str(), v[i].Gp, v[i].Gmid, v[i].Gfinal, v[i].G);
	}
    return 0;
}

