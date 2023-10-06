#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct {
	char e;
	int data;
	int parent;
	int lchild;
	int rchild;
}BTreeNode;

void InitNode(BTreeNode*& b) {
	b = (BTreeNode*)malloc(sizeof(BTreeNode));
	b->e = NULL;
	b->data = b->parent = b->lchild = b->rchild = -1;
}

void CreateNode(BTreeNode* btree[], int n) {
	int num, min1, min2, lnode, rnode;
	char e;
	for (int i = 0; i < 2 * n - 1; i++) {
		InitNode(btree[i]);
	}
	for (int i = 0; i < n; i++) {
		cin >> e;
		btree[i]->e = e;
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		btree[i]->data = num;
	}
	for (int i = n; i <= 2 * n - 2; i++) {
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for (int j = 0; j <= i - 1; j++) {
			if (btree[j]->parent == -1) {
				if (btree[j]->data < min1) {
					min2 = min1;
					rnode = lnode;
					min1 = btree[j]->data;
					lnode = j;
				}
				else if (btree[j]->data < min2) {
					min2 = btree[j]->data;
					rnode = j;
				}
			}
		}
		btree[i]->data = min1 + min2;
		btree[i]->lchild = lnode;
		btree[i]->rchild = rnode;
		btree[lnode]->parent = i;
		btree[rnode]->parent = i;
	}
}

void shuchu(BTreeNode* btree[], int n) {
	for (int i = 0; i < 2 * n - 1; i++) {
		printf("%4d", i);
		printf(":");
		printf("%4d", btree[i]->data);
		printf("%4d", btree[i]->parent);
		printf("%4d", btree[i]->lchild);
		printf("%4d", btree[i]->rchild);
		printf("\n");
	}
}

int main() {
	BTreeNode* btree[MAXSIZE];
	int n;
	cin >> n;
	CreateNode(btree, n);
	shuchu(btree, n);
	return 0;
}