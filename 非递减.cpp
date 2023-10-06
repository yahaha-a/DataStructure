#include <iostream>
using namespace std;

typedef struct LinkN {
	int data;
	struct LinkN* next;
}Linknode;

void CreateLink(Linknode* L, int n) {
	Linknode* s;
	int a;
	for (int i = 0; i < n; i++) {
		s = (Linknode*)malloc(sizeof(Linknode));
		cin >> a;
		s->next = NULL;
		s->data = a;
		L->next = s;
		L = s;
	}
}

int increase(Linknode* L) {
	Linknode* pre, * p;
	pre = L->next;
	p = pre->next;
	while (p != NULL) {
		if (p->data >= pre->data) {
			pre = pre->next;
			p = p->next;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int main() {
	Linknode* L;
	L = (Linknode*)malloc(sizeof(Linknode));
	L->next = NULL;
	int n;
	cin >> n;
	CreateLink(L, n);
	int a = increase(L);
	cout << a;
	free(L);
	return 0;
}