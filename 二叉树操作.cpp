#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct BTree {
	char data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTreeNode;

void CreateBTree(BTreeNode*& t, char* arry) {
	t = NULL;
	BTreeNode* p = NULL;
	BTreeNode* St[MAXSIZE];
	int top = -1, number = 0;
	while (*arry != NULL) {
		switch (*arry) {
		case'(':
			top++;
			St[top] = p;
			number = 1;
			break;
		case',':
			number = 2;
			break;
		case')':
			top--;
			break;
		default:
			p = (BTreeNode*)malloc(sizeof(BTreeNode));
			p->data = *arry;
			p->lchild = p->rchild = NULL;
			if (t == NULL) {
				t = p;
			}
			switch (number) {
			case 1:
				St[top]->lchild = p;
				break;
			case 2:
				St[top]->rchild = p;
				break;
			}
			number = 0;
			break;
		}
		arry++;
	}
}

void PreOrder(BTreeNode* t) {
	if (t != NULL) {
		cout << t->data << ' ';
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

void InOrder(BTreeNode* t) {
	if (t != NULL) {
		PreOrder(t->lchild);
		cout << t->data << ' ';
		PreOrder(t->rchild);
	}
}

void PostOrder(BTreeNode* t) {
	if (t != NULL) {
		PreOrder(t->lchild);
		PreOrder(t->rchild);
		cout << t->data << ' ';
	}
}

/*计算二叉树节点数*/
int Nodes(BTreeNode* t) {
	int lnodes, rnodes;
	if (t == NULL) {
		return 0;
	}
	lnodes = Nodes(t->lchild);
	rnodes = Nodes(t->rchild);
	return lnodes + rnodes + 1;
}

/*找出二叉树所有叶子节点*/
void DispLeaf(BTreeNode* t) {
	if (t == NULL) {
		return;
	}
	else if (t->lchild == NULL && t->rchild == NULL) {
		cout << t->data << ' ';
		return;
	}
	else {
		DispLeaf(t->lchild);
		DispLeaf(t->rchild);
	}
}

/*找出指定结点的层次*/
int Level(BTreeNode* t, char x) {
	static int h = 1;
	int l;
	if (t == NULL) {
		return 0;
	}
	else if (t->data == x) {
		return h;
	}
	else {
		h++;
		l = Level(t->lchild, x);
		if (l != NULL) {
			return l;
		}
		else {
			return Level(t->rchild, x);
		}
	}
}

/*找出指定层次的节点个数*/
void Lnodenum(BTreeNode* t, int k, int h, int& n) {
	if (t == NULL) {
		return;
	}
	else 
		if (k == h) {
			n++;
		}
		else if (h < k) {
			Lnodenum(t, k, h + 1, n);
			Lnodenum(t, k, h + 1, n);
		}
}

int main() {
	char arry[MAXSIZE] = "A(B(D(H,I),E),C(F(,J),G))";
	BTreeNode* t;
	CreateBTree(t, arry);
	cout << Nodes(t);
	cout << '\n';
	DispLeaf(t);
	cout << '\n';
	cout << Level(t, 'H');
	cout << '\n';
	int n = 0;
	Lnodenum(t, 2, 1, n);
	cout << n;
	cout << '\n';
	PreOrder(t);
	cout << '\n';
	InOrder(t);
	cout << '\n';
	PostOrder(t);
	return 0;
}