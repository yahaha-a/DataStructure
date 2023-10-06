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
		s->next = NULL;
		cin >> a;
		s->data = a;
		L->next = s;
		L = s;
	}
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

void Destory(linknode* L) {
	linknode* pre = L->next;
	linknode* p = pre->next;
	free(pre);
	pre = p;
	p = pre->next;
}

int main() {
	linknode* L;
	L = (linknode*)malloc(sizeof(linknode));
	int n;
	cin >> n;
	CreateLink(L, n);
	ForList(L);
	Destory(L);
	return 0;
}