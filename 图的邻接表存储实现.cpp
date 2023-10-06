#include <iostream>

using namespace std;

#define MAXSIZE 20

typedef struct Node {
	char data;
	struct Node* next;
}QuNode;

typedef struct {
	QuNode* FirstNode[MAXSIZE];
	int n, e;
}Queue;

void InitNode(QuNode*& n) {
	n = (QuNode*)malloc(sizeof(QuNode));
	n->data = NULL;
	n->next = NULL;
}

void InitQueue(Queue*& q) {
	q = (Queue*)malloc(sizeof(Queue));
	int i = 0;
	for (i; i < MAXSIZE; i++) {
		q->FirstNode[i] = NULL;
	}
	q->n = q->e = 0;
}

void CreateQueue(Queue*& q) {
	InitQueue(q);
	QuNode* p = NULL;
	cin >> q->n >> q->e;
	char ch;
	int i = 0;
	cin.get();
	while ((ch = cin.get()) != '\n') {
		InitNode(p);
		p->data = ch;
		q->FirstNode[i] = p;
		i++;
	}
	char m, n;
	for (i = 0; i < q->e; i++) {
		m = cin.get();
		n = cin.get();
		int j;
		for (j = 0; j < q->n; j++) {
			if (q->FirstNode[j]->data == m) {
				InitNode(p);
				p->data = n;
				p->next = q->FirstNode[j]->next;
				q->FirstNode[j]->next = p;
			}
		}
		for (j = 0; j < q->n; j++) {
			if (q->FirstNode[j]->data == n) {
				InitNode(p);
				p->data = m;
				p->next = q->FirstNode[j]->next;
				q->FirstNode[j]->next = p;
			}
		}
		cin.get();
	}
}

void PrintQueue(Queue* q) {
	QuNode* p = NULL;
	int i;
	for (i = 0; i < q->n; i++) {
		p = q->FirstNode[i];
		while (p != NULL) {
			cout << p->data << "->";
			p = p->next;
		}
		cout << "NULL" << '\n';
	}
}

int main() {
	Queue* q;
	CreateQueue(q);
	PrintQueue(q);
	return 0;
}