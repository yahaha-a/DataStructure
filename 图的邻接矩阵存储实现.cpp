#include <iostream>

using namespace std;

#define MAXSIZE 20

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

void CreateQueue(Queue*& q) {
	InitQueue(q);
	QuNode* top[MAXSIZE];
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

void PrintQueue(Queue* q) {
	int i = 0, j = 0;
	for (i; i < q->n; i++) {
		for (j; j < q->n; j++) {
			cout << q->queue[i][j] << ' ';
		}
		j = 0;
		cout << '\n';
	}
}

int main() {
	Queue* q = NULL;
	CreateQueue(q);
	PrintQueue(q);
	return 0;
}