#include <iostream>
using namespace std;

typedef struct linkn{
	int data;
	struct linkn* next;
}linknode;

void CreateLink(linknode* L, int n) {
	linknode* s;
	int a;
	for (int i = 0; i < n; i++) {
		s = (linknode*)malloc(sizeof(linknode));
		cin >> a;
		s->data = a;
		L->next = s;
		L = s;
	}
	L->next = NULL;
}

void ForList(linknode* L) {
	L = L->next;
	while (L != NULL) {
		cout << L->data << ' ';
		L = L->next;
	}
}

void DeleteSample(linknode* L) {
	L = L->next;
	linknode* M;
	linknode* N;
	while (L != NULL) {
		M = L;
		N = L->next;
		while (N != NULL) {
			if (N->data == L->data) {
				linknode* t = N;
				M->next = N->next;
				free(t);
				break;
			}
			M = M->next;
			N = N->next;
		}
		L = L->next;
	}
}

void CombineLink(linknode* L, linknode* M) {
	while (L->next != NULL) {
		L = L->next;
	}
	L->next = M->next;
}

int main() {
	linknode* L, * M;
	L = (linknode*)malloc(sizeof(linknode));
	M = (linknode*)malloc(sizeof(linknode));
	L->next = NULL;
	M->next = NULL;
	int n, m;
	cin >> n;
	CreateLink(L, n);
	cin >> m;
	CreateLink(M, m);
	CombineLink(L, M);
	DeleteSample(L);
	ForList(L);
	free(L);
	free(M);
	return 0;
}