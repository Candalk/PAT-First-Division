// C(Postorder Traversal).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
vector<int> pre, in,post;
struct node {
	int data;
	struct node *left,*right;
};

node *CreateTree(node *root,int i,int j,int k) {
	if (i > j)return NULL;
	root = new node;
	root->left = root->right = NULL;
	root->data = pre[i];
	int temp = pre[i];
	int t = k;
	while (in[t] != temp)t++;
	int len = t - k;
	root->left = CreateTree(root->left, i + 1, i + len, k);
	root->right = CreateTree(root->right, i + len+1, j, t + 1);
	return root;
}

//void mid(node *root) {
//
//	if (root == NULL)return;
//	mid(root->left);
//	printf("%d", root->data);
//	mid(root->right);
//}
int i = 0;
void last(node *root) {
	if (root == NULL)return;
	last(root->left);
	last(root->right);
	//printf("%d", root->data);
	post[i++]=root->data;
}
int main()
{


	int N;
	cin >> N;
	pre.resize(N);
	in.resize(N);
	post.resize(N);
	for (int i = 0; i < N; i++)cin >> pre[i];
	for (int i = 0; i < N; i++)cin >> in[i];

	node *root = NULL;
	root = CreateTree(root, 0, N - 1, 0);

	/*mid(root);
	cout << endl;*/
	last(root);
	//for(int i=0;i<post.size();i++)

	cout << post[0];
    return 0;
}

