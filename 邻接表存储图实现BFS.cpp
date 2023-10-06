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

typedef struct {
	QuNode* n[MAXSIZE];
	int rear;
	int front;
}queue;

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

void Initqueue(queue*& t) {
	t = (queue*)malloc(sizeof(queue));
	int i = 0;
	for (i; i < MAXSIZE; i++) {
		t->n[i] = NULL;
	}
	t->front = t->rear = -1;
}

QuNode* dequeue(queue* t) {
	if (t->front == t->rear) {
		return NULL;
	}
	else {
		t->front++;
		return t->n[t->front];
	}
}

void enqueue(queue* t, QuNode* q) {
	if (t->rear == MAXSIZE - 1) {
		return;
	}
	else {
		t->rear++;
		t->n[t->rear] = q;
	}
}

bool emptyqueue(queue* t) {
	return t->front == t->rear;
}

void BFS(Queue* q, char visited[], char e) {
	int num = 0;
	queue* t;
	Initqueue(t);
	int i = 0;
	for (i; i < q->n; i++) {
		if (q->FirstNode[i]->data == e) {
			visited[num] = e;
			num++;
			enqueue(t, q->FirstNode[i]);
			break;
		}
	}
	QuNode* n;
	while (!emptyqueue(t)) {
		n = dequeue(t);
		for (i = 0; i < q->n; i++) {
			if (q->FirstNode[i]->data == n->data) {
				n = q->FirstNode[i];
				break;
			}
		}
		cout << n->data;
		while (n->next != NULL) {
			bool flag = true;
			n = n->next;
			for (i = 0; i <= num; i++) {
				if (visited[i] == n->data) {
					flag = false;
				}
			}
			if (flag) {
				enqueue(t, n);
				visited[num] = n->data;
				num++;
			}
		}
	}
}

int main() {
	Queue* q;
	CreateQueue(q);
	char e;
	cin >> e;
	char visited[MAXSIZE];
	BFS(q, visited, e);
	return 0;
}