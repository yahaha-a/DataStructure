#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Lcode {
	ElemType data;
	struct Lcode* next;
}LinkCode;

void InitList(LinkCode*&L) {
	L = (LinkCode*)malloc(sizeof(LinkCode));
	L->next = NULL;
}

void TouCha(LinkCode*& L, ElemType a[], int n) {
	LinkCode* N;
	for (int i = 0; i < n; i++) {
		N = (LinkCode*)malloc(sizeof(LinkCode));
		N->data = a[i];
		N->next = L->next;
		L->next = N;
	}
}

void WeiCha(LinkCode*& L, ElemType a[], int n) {
	LinkCode* N;
	for (int i = 0; i < n; i++) {
		N = (LinkCode*)malloc(sizeof(LinkCode));
		N->data = a[i];
		L->next = N;
		L = N;
	}
}

void DestroyList(LinkCode*&L) {
	LinkCode* M = L, * N = L->next;
	while (N != NULL) {
		free(M);
		M = N;
		N = M->next;
	}
	free(M);
}

bool ListEmpty(LinkCode*L) {
	return(L->next == NULL);
}

int ListLength(LinkCode* L) {
	int n = 0;
	LinkCode* M = L;
	if (M->next != NULL) {
		n++;
		M = M->next;
	}
	return n;
}

void DisPList(LinkCode* L) {
	while (L != NULL) {
		cout << L->data << ' ';
		L = L->next;
	}
	cout << '\n';
}

ElemType GetElem(LinkCode* L, int i, ElemType &e) {
	int n = 0;
	while (n != i) {
		n++;
		L = L->next;
	}
	e = L->data;
	return e;
}

int LocateElem(LinkCode* L, ElemType e) {
	int n = 0;
	while (L->data != e) {
		n++;
		L = L->next;
	}
	return n;
}

bool ListInsert(LinkCode* L, int i, ElemType e) {
	int n = 0;
	while (L != NULL && n < i) {
		L = L->next;
		n++;
	}
	if (L != NULL) {
		LinkCode* S = (LinkCode*)malloc(sizeof(LinkCode));
		S->data = e;
		S->next = L->next;
		L->next = S;
		return true;
	}
	return false;
}

int main() {
	ElemType a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	LinkCode* L;
}