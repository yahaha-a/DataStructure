#include <iostream>
using namespace std;

#define MaxSize 6

typedef struct {
    int data[MaxSize];
    int front;
    int rear;
}SqQueue;

bool enQueue(SqQueue* q, int e) {
    if ((q->rear + 1) % MaxSize == q->front) {
        return false;
    }
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue* q, int e) {
    if ((q->front) == (q->rear)) {
        return false;
    }
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}

bool fun(SqQueue*& qu, int i)
{
    int e;
    int j = 1;
    int n = (qu->rear - qu->front + MaxSize) % MaxSize;
    if (i<1 || i>n) {
        return false;
    }
    for (j = 1; j <= n; j++)
    {
        deQueue(qu, e);
        if (j != i) {
            enQueue(qu, e);
        }
    }
    return true;
}

int main() {

    fun
}