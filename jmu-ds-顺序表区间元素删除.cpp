#include <iostream>
using namespace std;

typedef struct linkn {
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
		cout << L->data;
		if (L->next != NULL) {
			cout << ' ';
		}
		L = L->next;
	}
	cout << '\n';
}

void Delete(linknode* L, int m, int n) {
	linknode* M = L->next;
	while (M != NULL) {
		if (M->data >= m && M->data <= n) {
			linknode* t = M;
			L->next = M->next;
			free(t);
		}
		else {
			L = L->next;
		}
		M = L->next;
	}
}

int main() {
	linknode* L;
	L = (linknode*)malloc(sizeof(linknode));
	L->next = NULL;
	int x, m, n;
	cin >> x;
	CreateLink(L, x);
	cin >> m;
	cin >> n;
	Delete(L, m, n);
	ForList(L);
	free(L);
	return 0;
}