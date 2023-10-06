#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct jiedianxin {
	ElemType data;
	struct jiedianxin* next;
}jiedian;

void toucha(jiedian*& L, ElemType a[], int n) {
	jiedian* O;
	for (int i = 0; i < n; i++) {
		O = (jiedian*)malloc(sizeof(jiedian));
		O->data = a[i];
		O->next = L->next;
		L->next = O;
	}
}

void weicha(jiedian*& M, ElemType a[], int n) {
	jiedian* P;
	for (int i = 0; i < n; i++) {
		P = (jiedian*)malloc(sizeof(jiedian));
		P->data = a[i];
		M->next = P;
		M = P;
	}
}

int main() {
	jiedian* L, * M, * H1, * H2;
	L = (jiedian*)malloc(sizeof(jiedian));
	L->next = NULL;
	H1 = (jiedian*)malloc(sizeof(jiedian));
	H1 = L;
	M = (jiedian*)malloc(sizeof(jiedian));
	H2 = (jiedian*)malloc(sizeof(jiedian));
	M->next = NULL;
	H2 = M;
	ElemType a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	toucha(L, a, 10);
	weicha(M, a, 10);
	do{
		H1 = H1->next;
		cout << H1->data << ' ';
	} while (H1->next != NULL);
	cout << '\n';
	do {
		H2 = H2->next;
		cout << H2->data << ' ';
	} while (H2->next != NULL);
	free(L);
	free(M);
	free(H1);
	free(H2);
}