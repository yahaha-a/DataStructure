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
		cout << L->data << ' ';
		L = L->next;
	}
	cout << '\n';
}

void split(linknode* A, linknode* B) {
	linknode* p = A->next, * ra, * rb;
	B = (linknode*)malloc(sizeof(linknode));
	ra = A;
	rb = B;
	while (p != NULL) {
		if (p->data % 2 == 0) {
			ra->next = p;
			ra = p;
		}
		else {
			rb->next = p;
			rb = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
}
int main() {
	linknode* A, * B;
	A = (linknode*)malloc(sizeof(linknode));
	B = (linknode*)malloc(sizeof(linknode));
	A->next = NULL;
	B->next = NULL;
	int n;
	cin >> n;
	CreateLink(A, n);
	split(A, B);
	ForList(A);
	ForList(B);
	free(A);
	free(B);
	return 0;
}