#include <iostream>
using namespace std;

typedef struct qnode{
	int data;
	struct qnode* next;
}DataNode;

typedef struct {
	DataNode* front;
	DataNode* rear;
}LinkQuNode;

void InitQueue(LinkQuNode* q) {
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

void DestoryQueue(LinkQuNode* q) {
	DataNode* pre = q->front, * p;
	if (pre != NULL) {
		p = pre->next;
		while (p != NULL) {
			free(pre);
			pre = p;
			p = pre->next;
		}
		free(pre);
	}
	free(q);
}

bool QueueEmpty(LinkQuNode* q) {
	return (q->rear == NULL);
}

bool enQueue(LinkQuNode* q, int e) {
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL) {
		q->front = q->rear = p;
	}
	else {
		q->rear->next = p;
		q->rear = p;
	}
	return true;
}

bool deQueue(LinkQuNode* q, int &e) {
	if (q->rear == NULL) {
		return false;
	}
	DataNode* t = q->front;
	if (q->rear == q->front) {
		e = q->rear->data;
		q->rear = q->front = NULL;
	}
	else {
		e = q->front->data;
		q->front = t->next;
	}
	free(t);
	return true;
}