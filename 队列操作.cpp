#include <iostream>
using namespace std;

#define MAXSIZE 10

typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

bool Push(SqQueue* q, int x) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		return false;
	}
	else {
		q->rear = (q->rear + 1) % MAXSIZE;
		q->data[q->rear] = x;
		return true;
	}
}

bool Pop(SqQueue* q, int& x) {
	if (q->front == q->rear) {
		return false;
	}
	else {
		q->front = (q->front + 1) % MAXSIZE;
		x = q->data[q->front];
		return true;
	}
}

int Size(SqQueue* q) {
	return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

int main() {
	SqQueue* q = NULL;
	InitQueue(q);
	int n, e, m, x;
	cin >> n;
	while (n--) {
		cin >> e;
		switch (e) {
		case 1:
			cin >> m;
			Push(q, m);
			break;
		case 2:
			if (Pop(q, x)) {
				cout << x << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
			break;
		case 3:
			cout << Size(q) << '\n';
		}
	}
	return 0;
}

