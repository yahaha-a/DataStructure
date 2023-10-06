#include <iostream>
using namespace std;

typedef struct linkn {
	int data;
	struct linkn* next;
}linknode;

void CreateLink(linknode*& L, int n) {
	linknode* s, * l = L;
	int a;
	for (int i = 0; i < n; i++) {
		s = (linknode*)malloc(sizeof(linknode));
		cin >> a;
		s->data = a;
		l->next = s;
		l = s;
	}
}

void ForList(linknode* L) {
	L = L->next;
	while (L != NULL) {
		cout << L->data << ',';
		L = L->next;
	}
	cout << '\n';
}

void IncreaseInsert(linknode* L, int a) {
	linknode* N, * M = L;
	L = L->next;
	while (L != NULL) {
		if (a <= L->data) {
			N = (linknode*)malloc(sizeof(linknode));
			N->data = a;
			N->next = L;
			M->next = N;
			break;
		}
		if (L->next == NULL && L->data < a) {
			N = (linknode*)malloc(sizeof(linknode));
			N->data = a;
			L->next = N;
			break;
		}
		L = L->next;
		M = M->next;
	}
}

int main() {
	linknode* L;
	L = (linknode*)malloc(sizeof(linknode));
	L->next = NULL;
	int n, m;
	cin >> n;
	CreateLink(L, n);
	cin >> m;
	IncreaseInsert(L, m);
	ForList(L);
	return 0;
}