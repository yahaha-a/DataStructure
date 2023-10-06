#include <iostream>
using namespace std;

typedef struct LinkN {
	int data;
	struct LinkN* next;
	struct LinkN* prio;
}Linknode;

void CreateLink(Linknode* L, int N) {
	Linknode* p;
	Linknode* t = L;
	for (int i = 1; i <= N; i++) {
		p = (Linknode*)malloc(sizeof(Linknode));
		p->data = i;
		p->next = NULL;
		p->prio = L;
		L->next = p;
		L = p;
	}
	L->next = t->next;
	t->next->prio = L;
}

void LinkList(Linknode* L, int N) {
	int n;
	cin >> n;
	Linknode* p = L->next;
	L->next = NULL;
	while (N--) {
		for (int i = 1; i < n; i++) {
			p = p->next;
		}
		L->next = p;
		L = p;
		p = p->next;
		p->prio->prio->next = p;
		p->prio = p->prio->prio;
	}
	L->next = NULL;
}

void ForList(Linknode* L, int N) {
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

int main() {
	Linknode* L;
	L = (Linknode*)malloc(sizeof(Linknode));
	L->next = NULL;
	int N;
	cin >> N;
	CreateLink(L, N);
	LinkList(L, N);
	ForList(L, N);
	free(L);
	return 0;
}