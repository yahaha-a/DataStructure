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
	t->prio = L;
}

void ForList(Linknode* L, int N) {
	L = L->next;
	for (int i = 0; i < N; i++) {
		cout << L->data << ' ';
		L = L->next;
	}
}

int main() {
	Linknode* L;
	L = (Linknode*)malloc(sizeof(Linknode));
	L->next = NULL;
	int N;
	cin >> N;
	CreateLink(L, N);
	ForList(L, N);
	return 0;
}