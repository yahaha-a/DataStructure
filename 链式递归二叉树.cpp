#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct LinkT {
	char data;
	struct LinkT* lchild;
	struct LinkT* rchild;
}LinkTBNode;

void CreateLinkT(LinkTBNode*& t, char* arry) {
	LinkTBNode* St[MAXSIZE];
	int top = -1;
	t = NULL;
	LinkTBNode* p = NULL;
	int number = 0;
	while (*arry != '\0') {
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
			p = (LinkTBNode*)malloc(sizeof(LinkTBNode));
			p->data = *arry;
			p->lchild = p->rchild = NULL;
			if (t == NULL) {
				t = p;
			}
			if (number == 1) {
				St[top]->lchild = p;
				break;
			}
			else if(number == 2) {
				St[top]->rchild = p;
				break;
			}
			number = 0;
			break;
		}
		arry++;
	}
}

void PreOrder(LinkTBNode* t) {
	if (t != NULL) {
		cout << t->data;
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

int main() {
	LinkTBNode* t;
	char arry[MAXSIZE] = "A(B(D(,G)),C(E,F))";
	CreateLinkT(t, arry);
	PreOrder(t);
	return 0;
}