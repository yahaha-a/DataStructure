#include <iostream>
using namespace std;

typedef struct LinkN {
	int data;
	struct LinkN* next;
}LinkNode;

void CreateLink(LinkNode* L) {
	LinkNode* t;
	int n;
	while (true) {
		t = (LinkNode*)malloc(sizeof(LinkNode));
		cin >> n;
		if (n == -1) {
			break;
		}
		t->data = n;
		t->next = NULL;
		L->next = t;
		L = t;
	}
}

void LinkList(LinkNode* M, LinkNode* N) {
	LinkNode* O, * P;
	O = M->next;
	P = N->next;
	while (O != NULL && P != NULL) {
		if (O->data >= P->data) {
			M->next = P;
			M = P;
			P = P->next;
		}
		else if (O->data < P->data) {
			M->next = O;
			M = O;
			O = O->next;
		}
	}
	if (O == NULL && P == NULL) {
		M->next = NULL;
	}
	if (O != NULL) {
		M->next = O;
	}
	if (P != NULL) {
		M->next = P;
	}
}

void ForLink(LinkNode* L) {
	LinkNode* t = L->next;
	if (t == NULL) {
		cout << "NULL";
	}
	while (t != NULL) {
		cout << t->data;
		if (t->next != NULL) {
			cout << ' ';
		}
		t = t->next;
	}
}

void DestoryLink(LinkNode* L) {
	LinkNode* pre = L->next;
	LinkNode* p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
}

int main() {
	LinkNode* M, * N;
	M = (LinkNode*)malloc(sizeof(LinkNode));
	N = (LinkNode*)malloc(sizeof(LinkNode));
	M->next = NULL;
	N->next = NULL;
	CreateLink(M);
	CreateLink(N);
	LinkList(M, N);
	ForLink(M);
	return 0;
}