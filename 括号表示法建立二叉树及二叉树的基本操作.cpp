#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct BT{
	char data;
	struct BT* lchild;
	struct BT* rchild;
}BTreeNode;

typedef struct {
	BTreeNode* btree[MAXSIZE];
	int top;
}BTreeSq;

void CreateArry(char* Arry) {
	while ((*Arry = cin.get()) != '\n') {
		Arry++;
	}
	*Arry = '\0';
}

void InitBT(BTreeNode*& t) {
	t = (BTreeNode*)malloc(sizeof(BTreeNode));
	t->data = NULL;
	t->lchild = NULL;
	t->rchild = NULL;
}

void InitBTree(BTreeSq*& b) {
	b = (BTreeSq*)malloc(sizeof(BTreeSq));
	b->top = -1;
}

bool Push(BTreeSq* b, BTreeNode* p) {
	if (b->top == MAXSIZE) {
		return false;
	}
	else {
		b->top++;
		b->btree[b->top] = p;
		return true;
	}
}

bool Pop(BTreeSq* b) {
	if (b->top == -1) {
		return false;
	}
	else {
		b->top--;
	}
}

BTreeNode* Get(BTreeSq* b) {
	return b->btree[b->top];
}

void CreateBTree(BTreeNode*& t, BTreeSq* b, char* Arry) {
	BTreeNode* p = NULL;
	int number = 0;
	while (*Arry != '\0') {
		switch (*Arry) {
		case '(':
			number = 1;
			Push(b, p);
			break;
		case ',' :
			number = 2;
			break;
		case ')':
			Pop(b);
			break;
		default:
			InitBT(p);
			p->data = *Arry;
			if (t == NULL) {
				t = p;
			}
			switch (number) {
			case 1:
				Get(b)->lchild = p;
				break;
			case 2:
				Get(b)->rchild = p;
				break;
			}
			break;
			number = 0;
		}
		Arry++;
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
		InOrder(t->lchild);
		cout << t->data << ' ';
		InOrder(t->rchild);
	}
}

void PostOrder(BTreeNode* t) {
	if (t != NULL) {
		PostOrder(t->lchild);
		PostOrder(t->rchild);
		cout << t->data << ' ';
	}
}

int Heigh(BTreeNode* t) {
	int l, r;
	if (t == NULL) {
		return 0;
	}
	else {
		l = Heigh(t->lchild);
		r = Heigh(t->rchild);
		if (l > r) {
			return l + 1;
		}
		else {
			return r + 1;
		}
	}
}

int Node(BTreeNode* t) {
	if (t == NULL) {
		return 0;
	}
	else {
		return Node(t->lchild) + Node(t->rchild) + 1;
	}
}

int TreeNode(BTreeNode* t) {
	int l, r;
	if (t == NULL) {
		return 0;
	}
	else if (t->lchild == NULL && t->rchild == NULL) {
		return 1;
	}
	else {
		l = TreeNode(t->lchild);
		r = TreeNode(t->rchild);
		return l + r;
	}
}

int main() {
	BTreeNode* t = NULL;
	BTreeSq* b = NULL;
	InitBTree(b);
	char Arry[MAXSIZE];
	CreateArry(Arry);
	CreateBTree(t, b, Arry);
	cout << "高度:" << Heigh(t) << '\n';
	cout << "结点数:" << Node(t) << '\n';
	cout << "叶子结点数:" << TreeNode(t) << '\n';
	cout << "先序遍历序列:";
	PreOrder(t);
	cout << "\n中序遍历序列:";
	InOrder(t);
	cout << "\n后序遍历序列:";
	PostOrder(t);
	return 0;
}