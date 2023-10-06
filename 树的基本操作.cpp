#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

typedef struct {
	BTNode* STBT[MAXSIZE];
	int top = -1;
}ArryStBT;

void CreateArry(char* arry) {
	while ((*arry = cin.get()) != '\n') {
		arry++;
	}
	*arry = '\0';
}

void InitBTNode(BTNode*& b) {
	b = (BTNode*)malloc(sizeof(BTNode));
	b->lchild = NULL;
	b->rchild = NULL;
}

void CreateBTree(BTNode* b, char* arry) {
	int k = 0;
	BTNode* t;
	ArryStBT* Arryst;
	while (*arry != '\0') {
		switch (*arry) {
		case '(' :
			k = 1;
			Arryst->top++;
			Arryst->STBT[Arryst->top] = t;
			break;
		case ')':
			Arryst->top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			InitBTNode(t);
			t->data = *arry;
			if (b == NULL) {
				b = t;
			}
			else {
				switch (k) {
				case 1:
					Arryst->STBT[Arryst->top]->lchild = t;
					break;
				case 2:
					Arryst->STBT[Arryst->top]->rchild = t;
					break;
				}
			}
		}
		arry++;
	}
}

void DestoryBTree(BTNode* b) {
	if (b == NULL) {
		return;
	}
	else {
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		free(b);
	}
}

BTNode* LchildNode(BTNode* b) {
	return b->lchild;
}

BTNode* RchildNode(BTNode* b) {
	return b->rchild;
}

int BTHeight(BTNode* b) {
	int Lchild, Rchild;
	if (b == NULL) {
		return 0;
	}
	else {
		Lchild = BTHeight(b->lchild);
		Rchild = BTHeight(b->rchild);
		return (Lchild > Rchild) ? (Lchild + 1) : (Rchild + 1);
	}
}

void DisoBTree(BTNode* b) {
	if (b == NULL) {
		return;
	}
	else {
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL) {
			cout << '(';
			DisoBTree(b->lchild);
			if (b->rchild != NULL) {
				cout << ',';
			}
			DisoBTree(b->rchild);
			cout << ')';
		}
	}
}

BTNode* FindNode(BTNode* b, int e) {
	BTNode* p;
	if (b == NULL) {
		return NULL;
	}
	else if (b->data == e) {
		return b;
	}
	else {
		p = FindNode(b->lchild, e);
		if (p != NULL) {
			return p;
		}
		else {
			return FindNode(b->rchild, e);
		}
	}
}

void PreOrder(BTNode* b) {
	if (b != NULL) {
		cout << b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void InOrder(BTNode* b) {
	if (b != NULL) {
		InOrder(b->lchild);
		cout << b->data;
		InOrder(b->rchild);
	}
}

void PostOrder(BTNode* b) {
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data;
	}
}




