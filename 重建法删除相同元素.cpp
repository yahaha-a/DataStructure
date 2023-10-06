#include <iostream>
using namespace std;

typedef int ElemType;

#define MAXSIZE 100

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;

void deletesame(SqList*& L) {
	int i = 0, j = 1;
	for (j; j < L->length; j++) {
		if (L->data[i] != L->data[j]) {
			i++;
			L->data[i] = L->data[j];
		}
	}
	L->length = i + 1;
}

int main() {
	SqList* L;
	L = (SqList*)malloc(sizeof(SqList));
	cin >> L->length;
	for (int i = 0; i < L->length; i++) {
		cin >> L->data[i];
	}
	deletesame(L);
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i];
	}
	free(L);
	return 0;
}