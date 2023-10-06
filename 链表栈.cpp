#include <iostream>
using namespace std;

typedef struct LinkN{
	int data;
	struct LinkN* next;
}LinkStNode;

void InitStack(LinkStNode*& s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

void DestoryStack(LinkStNode* s) {
	LinkStNode* pre = s, * p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool stackEmpty(LinkStNode* s) {
	return (s->next == NULL);
}

bool Push(LinkStNode* s, int e) {
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}

bool Pop(LinkStNode* s, int e) {
	LinkStNode* p = s->next;
	if (s->next == NULL) {
		return false;
	}
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode* s, int e) {
	if (s->next == NULL) {
		return false;
	}
	e = s->next->data;
	return true;
}