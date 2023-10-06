#include<iostream>
using namespace std;

#define MAXSIZE 10

typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;

void fugai(SqList* L) {
	int i = 0, j = L->length - 1;
	ElemType base = L->data[0];
	while (i < j) {
		while (i < j && L->data[j] > base) {
			j--;
		}
		L->data[i] = L->data[j];
		while (i < j && L->data[i] <= base) {
			i++;
		}
		L->data[j] = L->data[i];
	}
	L->data[i] = base;
}

int main() {
	SqList* L;
	L = (SqList*)malloc(sizeof(SqList));
	cout << "请输入长度:" << '\n';
	cin >> L->length;
	cout << "请输入" << L->length << "个值:" << "\n";
	for (int i = 0; i < L->length; i++) {
		cin >> L->data[i];
	}
	fugai(L);
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i] << ' ';
	}
	free(L);
	return 0;
}