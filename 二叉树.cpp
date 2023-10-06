#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct BTree {
	char data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTreeNode;

void CreateArry(char* arry) {
	while ((*arry = cin.get()) != '\n') {
		arry++;
	}
	*arry = '\0';
}

void CreateBTree(BTreeNode*& t, char* arry) {
	BTreeNode* p = NULL;
	t = NULL;
	BTreeNode* St[MAXSIZE];
	int top = -1, number = 0;
	while (*arry != '\0') {
		switch (*arry) {
		case'(':
			number = 1;
			top++;
			St[top] = p;
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

void DestoryBTree(BTreeNode* t) {
	if (t != NULL) {
		DestoryBTree(t->lchild);
		DestoryBTree(t->rchild);
		free(t);
	}
}

BTreeNode* FindNode(BTreeNode* t, char e) {
	BTreeNode* p;
	if (t == NULL) {
		return NULL;
	}
	if (t->data == e) {
		return t;
	}
	else {
		p = FindNode(t->lchild, e);
		if (p != NULL) {
			return p;
		}
		else {
			return FindNode(t->rchild, e);
		}
	}
}

BTreeNode* LchildNode(BTreeNode* p) {
	return p->lchild;
}

BTreeNode* RchildNode(BTreeNode* p) {
	return p->rchild;
}

int BTHeight(BTreeNode* t) {
	int lchildh, rchildh;
	if (t == NULL) {
		return 0;
	}
	lchildh = BTHeight(t->lchild);
	rchildh = BTHeight(t->rchild);
	return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	
}

void DispBTree(BTreeNode* t) {
	if (t != NULL) {
		if (t->lchild == NULL && t->rchild == NULL) {
			cout << t->data;
		}
		else {
			cout << t->data << '(';
			DispBTree(t->lchild);
			cout << ',';
			DispBTree(t->rchild);
			cout << ')';
		}
	}
}

int main() {
	BTreeNode* t;
	char arry[MAXSIZE];
	CreateArry(arry);
	CreateBTree(t, arry);
	PreOrder(t);
	cout << '\n';
	InOrder(t);
	cout << '\n';
	PostOrder(t);
	cout << '\n';
	char e;
	cin >> e;
	BTreeNode* p = FindNode(t, e);
	cout << p->data;
	cout << '\n';
	cout << LchildNode(t)->data;
	cout << '\n';
	cout << RchildNode(t)->data;
	cout << '\n';
	cout << BTHeight(t);
	cout << '\n';
	DispBTree(t);
	return 0;
}