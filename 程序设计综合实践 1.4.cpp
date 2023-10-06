#include <iostream>
using namespace std;

typedef struct LinkN {
	int data;
	struct LinkN* next;
}LinkNode;

void CreateLink(LinkNode* L) {
	LinkNode* t;
	int n;
	do{
		cin >> n;
		t = (LinkNode*)malloc(sizeof(LinkNode));
		t->data = n;
		t->next = L->next;
		L->next = t;
	} while ((cin.get()) != '\n');
}

void SortLink(LinkNode* L) {
	LinkNode* t = L->next;
	LinkNode* pre, * p, * l;
	int count = 0, num = 0;
	while (t != NULL) {
		t = t->next;
		count++;
	}
	for (int i = 0; i < count - 1; i++) {
		num = count - i - 1;
		l = L;
		pre = L->next;
		p = pre->next;
		while (num--) {
			if (pre->data > p->data) {
				pre->next = p->next;
				p->next = pre;
				l->next = p;
			}
			l = l->next;
			pre = l->next;
			p = pre->next;
		}
	}
}

void Split(LinkNode* L, LinkNode* O) {
	LinkNode* pre = L;
	LinkNode* p = pre->next;
	while (p != NULL) {
		if ((p->data % 2) == 0) {
			pre->next = p->next;
			O->next = p;
			O = p;
			O->next = NULL;
			p = pre->next;
		}
		else {
			pre = pre->next;
			p = pre->next;
		}
	}
}

void ForLink(LinkNode* L) {
	LinkNode* t = L->next;
	while (t != NULL) {
		cout << t->data;
		if (t->next != NULL) {
			cout << "->";
		}
		t = t->next;
	}
	cout << '\n';
}

void DestoryLink(LinkNode* L) {
	LinkNode* pre = L;
	LinkNode* p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

int main() {
	LinkNode* L, * O;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	O = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	O->next = NULL;
	CreateLink(L);
	SortLink(L);
	ForLink(L);
	Split(L, O);
	ForLink(L);
	ForLink(O);
	DestoryLink(L);
	DestoryLink(O);
	return 0;
}