#include <iostream>
using namespace std;

#define MAXSIZE 1000

typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitSqQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

bool Push(SqQueue* q, int e) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		return false;
	}
	else {
		q->rear = (q->rear + 1) % MAXSIZE;
		q->data[q->rear] = e;
		return true;
	}
}

bool Pop(SqQueue* q, int& e) {
	if (q->front == q->rear) {
		return false;
	}
	else {
		q->front = (q->front + 1) % MAXSIZE;
		e = q->data[q->front];
		return true;
	}
}

bool Empty(SqQueue* q) {
	return (q->rear == q->front);
}

void yewu(SqQueue* A, SqQueue* B, int* queue) {
	while (*queue != '\0') {
		if (*queue % 2 == 0) {
			Push(B, *queue);
		}
		else if(*queue % 2 == 1) {
			Push(A, *queue);
		}
		queue++;
	}
	int e;
	while (!Empty(A) || !Empty(B)) {
		if (Pop(A, e)) {
			cout << e;
			if (!Empty(A) || !Empty(B)) {
				cout << ' ';
			}
		}
		if (Pop(A, e)) {
			cout << e;
			if (!Empty(A) || !Empty(B)) {
				cout << ' ';
			}
		}
		if (Pop(B, e)) {
			cout << e;
			if (!Empty(A) || !Empty(B)) {
				cout << ' ';
			}
		}
	}
}

int main() {
	int queue[MAXSIZE];
	SqQueue* A = NULL, * B = NULL;
	InitSqQueue(A);
	InitSqQueue(B);
	int x;
	cin >> x;
	int e;
	for (int i = 0; i < x; i++) {
		cin >> e;
		queue[i] = e;
	}
	queue[x] = '\0';
	yewu(A, B, queue);
	return 0;
}