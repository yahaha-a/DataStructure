#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct BT {
	char data;
	int lchildn;
	int rchildn;
	struct BT* lchild;
	struct BT* rchild;
}BTreeNode;

typedef struct {
	BTreeNode* btree[MAXSIZE];
	int top;
}BTree;

typedef struct {
	BTreeNode* que[MAXSIZE];
	int rear;
	int front;
}BTreeQue;

void InitBTreeNode(BTreeNode*& n) {
	n = (BTreeNode*)malloc(sizeof(BTreeNode));
	n->data = NULL;
	n->lchildn = 0;
	n->rchildn = 0;
	n->lchild = NULL;
	n->rchild = NULL;
}

void InitBTree(BTree*& b) {
	b = (BTree*)malloc(sizeof(BTree));
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		InitBTreeNode(b->btree[i]);
	}
	b->top = -1;
}

void InitBTreeQue(BTreeQue*& q) {
	q = (BTreeQue*)malloc(sizeof(BTreeQue));
	q->rear = 0;
	q->front = 0;
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		InitBTreeNode(q->que[i]);
	}
}

void CreateArry(char* arry) {
	while ((*arry = cin.get()) != '\n') {
		arry++;
	}
	*arry = '\0';
}

bool Push(BTree* b, BTreeNode* n) {
	if (b->top == MAXSIZE) {
		return false;
	}
	else {
		b->top++;
		b->btree[b->top] = n;
		return true;
	}
}

bool Pop(BTree* b) {
	if (b->top == -1) {
		return false;
	}
	else {
		b->top--;
		return true;
	}
}

bool enQue(BTreeQue* q, BTreeNode* t) {
	if (q->rear == MAXSIZE) {
		return false;
	}
	else {
		q->que[q->rear] = t;
		q->rear++;
		return true;
	}
}

BTreeNode* deQue(BTreeQue* q) {
	if (q->front == q->rear) {
		return NULL;
	}
	else {
		q->front++;
		return q->que[q->front - 1];
	}
}

BTreeNode* Get(BTree* b) {
	return b->btree[b->top];
}

void CreateBTree(BTree*& b, BTreeNode*& n, char* arry) {
	BTreeNode* t;
	InitBTreeNode(t);
	t->data = *arry;
	arry++;
	n = t;
	Push(b, t);
	while (*arry != '\0') {
		switch (*arry) {
		case '#':
			if (Get(b)->lchildn == 0 && Get(b)->rchildn == 0) {
				Get(b)->lchildn = 1;
				arry++;
				break;
			}
			else if (Get(b)->lchildn == 1 && Get(b)->rchildn == 0) {
				Get(b)->rchildn = 1;
				arry++;
				break;
			}
			else if (Get(b)->lchildn == 1 && Get(b)->rchildn == 1) {
				Pop(b);
			}
			break;
		default:
			InitBTreeNode(t);
			t->data = *arry;
			if (Get(b)->lchildn == 0 && Get(b)->rchildn == 0) {
				Get(b)->lchild = t;
				Get(b)->lchildn = 1;
				Push(b, t);
				arry++;
				break;
			}
			else if (Get(b)->lchildn == 1 && Get(b)->rchildn == 0) {
				Get(b)->rchild = t;
				Get(b)->rchildn = 1;
				Push(b, t);
				arry++;
				break;
			}
			else if (Get(b)->lchildn == 1 && Get(b)->rchildn == 1) {
				Pop(b);
			}
			break;
		}
	}
}

void PreOrder(BTreeQue* q, BTreeNode* t) {
	BTreeNode* n;
	enQue(q, t);
	cout << "层序遍历结果:";
	while(q->front != q->rear) {
		n = deQue(q);
		cout << n->data << ' ';
		if (n->lchild != NULL) {
			enQue(q, n->lchild);
		}
		if (n->rchild != NULL) {
			enQue(q, n->rchild);
		}
	}
	cout << '\n';
}

int i, j;

void jiedian(BTreeNode* n) {
	if (n == NULL) {
		return;
	}
	if (n->lchild != NULL && n->rchild != NULL) {
		i++;
	}
	else if ((n->lchild != NULL && n->rchild == NULL) || (n->lchild == NULL && n->rchild != NULL)) {
		j++;
	}
	if (n != NULL) {
		jiedian(n->lchild);
		jiedian(n->rchild);
	}
}

int main() {
	BTree* b;
	BTreeNode* n;
	BTreeQue* q = NULL;
	InitBTree(b);
	InitBTreeQue(q);
	InitBTreeNode(n);
	char arry[MAXSIZE];
	CreateArry(arry);
	CreateBTree(b, n, arry);
	PreOrder(q, n);
	jiedian(n);
	cout << "二叉树度为1结点数:" << j << '\n' << "二叉树度为2结点数:" << i;
	return 0;
}