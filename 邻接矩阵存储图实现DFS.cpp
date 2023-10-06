#include <iostream>

using namespace std;

#define MAXSIZE 30

typedef struct {
	int data;
	char ch;
}QuNode;

typedef struct {
	int queue[MAXSIZE][MAXSIZE];
	int n, e;
}Queue;

void InitNode(QuNode*& n) {
	n = (QuNode*)malloc(sizeof(QuNode));
	n->ch = NULL;
}

void InitQueue(Queue*& q) {
	q = (Queue*)malloc(sizeof(Queue));
	int i = 0, j = 0;
	for (i = 0; i < MAXSIZE; i++) {
		for (j; j < MAXSIZE; j++) {
			q->queue[i][j] = 0;
		}
		j = 0;
	}
	q->n = q->e = 0;
}

void CreateQueue(Queue*& q, QuNode* top[]) {
	InitQueue(q);
	QuNode* p = NULL;
	int num = 0;
	char ch;
	while ((ch = cin.get()) != '#') {
		InitNode(p);
		p->data = num;
		p->ch = ch;
		top[num] = p;
		num++;
	}
	q->n = num;
	char m, n;
	bool flag = true;
	while (flag) {
		if ((ch = cin.get()) == '#') {
			flag = false;
		}
		m = cin.get();
		n = cin.get();
		if (m == '#' && n == '#') {
			break;
		}
		int i = 0, j = 0, k = 0;
		for (i; i < num; i++) {
			if (m == top[i]->ch) {
				j = top[i]->data;
			}
			if (n == top[i]->ch) {
				k = top[i]->data;
			}
		}
		q->queue[j][k] = 1;
		q->queue[k][j] = 1;
	}
}

void DFS(Queue* q, QuNode* top[], int visited[], char e) {
	cout << e;
	int i = 0;
	for (i; i < q->n; i++) {
		if (e == top[i]->ch) {
			visited[i] = 1;
			break;
		}
	}
	int j = 0;
	for (j; j < q->n; j++) {
		if (q->queue[i][j] == 1) {
			if (visited[j] == 0) {
				e = top[j]->ch;
				DFS(q, top, visited, e);
			}
		}
	}
}

int main() {
	Queue* q = NULL;
	QuNode* top[MAXSIZE];
	CreateQueue(q, top);
	char e;
	cin >> e;
	int visited[MAXSIZE];
	int i = 0;
	for (i; i < q->n; i++) {
		visited[i] = 0;
	}
	DFS(q, top, visited, e);
	return 0;
}