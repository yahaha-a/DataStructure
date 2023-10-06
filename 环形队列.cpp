#include <iostream>
using namespace std;

#define MaxSize 100

typedef struct {
	int data[MaxSize];
	int front;
	int rear;
}Queue;

void InitQueue(Queue* q) {
	q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = 0;
}

void DestoryQueue(Queue* q) {
	free(q);
}

bool QueueEmpty(Queue* q) {
	return (q->front == q->rear);
}

bool enQueue(Queue* q, int e) {
	if ((q->rear + 1) % MaxSize == q->front) {
		return false;
	}
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

bool deQueue(Queue* q, int e) {
	if ((q->front) == (q->rear)) {
		return false;
	}
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}

int Count(Queue* q) {
	return ((q->rear - q->front + MaxSize) % MaxSize);
}