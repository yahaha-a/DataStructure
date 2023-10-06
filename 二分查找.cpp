#include <iostream>

using namespace std;

#define MAXSIZE 100

typedef struct {
	int number[MAXSIZE];
	int n;
}List;

void InitList(List*& L) {
	L = (List*)malloc(sizeof(List));
	for (int i = 0; i < MAXSIZE; i++) {
		L->number[i] = 0;
	}
	L->n = 0;
}

void CreateList(List* L, int m) {
	int i = 0;
	for (i; i < m; i++) {
		cin >> L->number[i];
		L->n++;
	}
}

int erfen(List* L, int e, int& n) {
	int i = 0, j = L->n - 1;
	int mid;
	while (i <= j) {
		mid = (i + j) / 2;
		if (L->number[mid] == e) {
			n++;
			return mid;
		}
		else if (L->number[mid] < e) {
			i = mid + 1;
		}
		else if (L->number[mid] > e) {
			j = mid - 1;
		}
		n++;
	}
	return -1;
}

int main() {
	List* L;
	InitList(L);
	int m;
	cin >> m;
	CreateList(L, m);
	int e, n = 0;
	cin >> e;
	cout << erfen(L, e, n) << '\n' << n;
	return 0;
}