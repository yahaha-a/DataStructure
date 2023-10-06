#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct BTree {
	char data;
	struct BTree* lchild;
	struct BTree* rchild;
}BTreeNode;

typedef struct Sq{
	BTreeNode* Sq[MAXSIZE];
	int front = -1;
	int rear = 0;
}Squee;

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

void LevelOrder(BTreeNode* t) {
	Squee* sq = (Squee*)malloc(sizeof(Squee));
		sq->Sq[sq->rear++] = t;
		while (sq->rear != sq->front) {
			if (t->lchild != NULL) {
				sq->Sq[sq->rear++] = t->lchild;
			}
			if (t->rchild != NULL) {
				sq->Sq[sq->rear++] = t->rchild;
			}
			cout << sq->Sq[sq->front++]->data;
		}
}

int main() {
	char arry[MAXSIZE];
	BTreeNode* t;
	CreateArry(arry);
	CreateBTree(t, arry);
	LevelOrder(t);
	return 0;
}