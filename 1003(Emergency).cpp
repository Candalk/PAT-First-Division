// 1003(Emergency).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int e[510][510], //��¼ͼ
weight[510], //weight���ڼ�¼�����Ȩ��
dis[510],//dis[i]��ʾ�ӳ����㵽i������·����·������
num[510],//num[i]��ʾ�ӳ����㵽i�ڵ����·��������
w[510];//w[i]��¼�ӳ����㵽i���Ԯ�ӵ���Ŀ֮��
bool visit[510];
const int inf = 9999999;
int main()
{

	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++)
		cin >> weight[i];
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		e[a][b] = c;
		e[b][a] = c;
	}

	dis[C1] = 0;
	w[C1] = weight[C1];
	num[C1] = 1;

	for (int i = 0; i < N; i++) {
		int u = -1, minn = inf;//u��������һ����̾���ĵ���±꣬minn���ڼ�¼��̾���

		//��һ������õ���̵���û�з��ʹ��ĵ�
		for (int j = 0; j < N; j++) {
			if (visit[j] == false && dis[j] < minn) {//�ҵ�δ���ʹ��õ�j����j�㵽��ʼ��ľ������
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)break;//������еĵ㶼�����ˣ�ֹͣ
		visit[u] = true;//��Ǹõ��Ѿ�����
		for (int v = 0; v < N; v++) {
			if (visit[v] == false && e[u][v] != inf) {//�����һ����û�з��ʹ�����������ͨ��
				if (dis[u] + e[u][v] < dis[v]) {//����ӳ����㵽v��·�����ȼ�����
					dis[v] = dis[u] + e[u][v];//����dis[v]
					num[v] = num[u];		  //���Ҹ������·��·������
					w[v] = w[u] + weight[v];  //���¾�Ԯ�ӵ���Ŀ
				}
				else if (dis[u] + e[u][v] == dis[v]) {//�����ȣ��ǾͲ��ø���dis[v],ֻ��Ҫ����num[v]�������·��·����Ŀ����Ҫ�Ƚ�Ȩ���Ƿ����ӣ�
					num[v] = num[v] + num[u];
					if (w[u] + weight[v] > w[v])	 //�����Ԯ�ӵ���Ŀ�����ˣ�w[v] = w[u] + weight[v];
						w[v] = w[u] + weight[v];
				}
			}
		}	
	}

	printf("%d %d", num[C2], w[C2]);
    return 0;
}

