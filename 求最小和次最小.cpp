#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct {
	int data;
	int parent;
	int lchild;
	int rchild;
}BTreeNode;

void CreateArry(int* number) {
	do {
		cin >> *number;
		number++;
	} while (cin.get() != '\n');
	*number = '\0';
}

int ArryNumber(int* number) {
	int i = 0;
	while (*number != '\0') {
		number++;
		i++;
	}
	return i;
}

void InitBTree(BTreeNode*& b) {
	b = (BTreeNode*)malloc(sizeof(BTreeNode));
	b->data = b->parent = b->lchild = b->rchild = -1;
}

void CreateBTree(BTreeNode* btree[], int number[], int n) {
	int min1, min2, lnode, rnode;
	for (int i = 0; i < 2 * n - 1; i++) {
		InitBTree(btree[i]);
	}
	for (int i = 0; i < n; i++) {
		btree[i]->data = number[i];
	}
	for (int j = n; j < 2 * n - 1; j++) {
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for (int k = 0; k < j; k++) {
			if (btree[k]->parent == -1) {
				if (btree[k]->data < min1) {
					min2 = min1;
					rnode = lnode;
					min1 = btree[k]->data;
					lnode = k;
				}
				else if (btree[k]->data < min2) {
					min2 = btree[k]->data;
					rnode = k;
				}
			}	
		}
		btree[j]->data = min1 + min2;
		btree[j]->lchild = lnode;
		btree[j]->rchild = rnode;
		btree[lnode]->parent = j;
		btree[rnode]->parent = j;
	}
}
	
void MinChild(BTreeNode* btree[], int n) {
	cout << "min1:" << btree[btree[n]->lchild]->data;
	cout << ",min1_sub:" << btree[n]->lchild;
	cout << '\n';
	cout << "min2:" << btree[btree[n]->rchild]->data;
	cout << ",min2_sub:" << btree[n]->rchild;
}

int main() {
	int number[MAXSIZE];
	CreateArry(number);
	BTreeNode* btree[MAXSIZE];
	CreateBTree(btree, number, ArryNumber(number));
	MinChild(btree, ArryNumber(number));
	return 0;
}