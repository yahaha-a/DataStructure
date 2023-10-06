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
		t->next = L->next;
		L->next = t;
	}
}

void ForLink(LinkNode* L) {
	LinkNode* t = L->next;
	while (t != NULL) {
		cout << t->data <<' ';
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
	LinkNode* L;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	CreateLink(L);
	ForLink(L);
	DestoryLink(L);
	free(L);
	return 0;
}