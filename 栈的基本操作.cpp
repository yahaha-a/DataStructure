#include <iostream>
using namespace std;

typedef struct LinkS {
	int data;
	struct LinkS* next;
	int top;
}LinkSqack;

void InitSqack(LinkSqack*& S) {
	S = (LinkSqack*)malloc(sizeof(LinkSqack));
	S->next = NULL;
	S->top = 0;
}

void Push(LinkSqack* S, int e) {
	LinkSqack* t = (LinkSqack*)malloc(sizeof(LinkSqack));
	t->data = e;
	t->next = S->next;
	S->next = t;
	S->top++;
}
int Pop(LinkSqack* S) {
	LinkSqack* t = S->next;
	S->next = t->next;
	 
	S->top--;
	return t->data;
}

//void ForLink(LinkSqack* S) {
//	S = S->next;
//	while (S != NULL) {
//		cout << S->data << ' ';
//		S = S->next;
//	}
//}

void ForLink(LinkSqack* S) {
	if (S == NULL) {
		return;
	}
	ForLink(S->next);
	cout << S->data << ' ';
}

int main() {
	LinkSqack* S;
	InitSqack(S);
	int e;
	int i;
	cin >> i;
	while (i--) {
		cin >> e;
		if (e == 0) {
			if (S->next == NULL) {
				cout << "EMPTY" << ' ';
			}
			else {
				cout << Pop(S) << ' ';
			}
		}
		else {
			if (S->top == 10) {
				cout << "FULL" << ' ';
			}
			else {
				Push(S, e);
			}
		}
	}
	cout << '\n';	
	ForLink(S->next);
	return 0;
}