#include <iostream>
using namespace std;

typedef struct LinkS{
	char data;
	struct LinkS* next;
}LinkSqack;

void InitSqack(LinkSqack*& S) {
	S = (LinkSqack*)malloc(sizeof(LinkSqack));
	S->next = NULL;
}

void Push(LinkSqack* S, char e) {
	LinkSqack* t;
	t = (LinkSqack*)malloc(sizeof(LinkSqack));
	t->data = e;
	t->next = S->next;
	S->next = t;
}

char get(LinkSqack* S) {
	if (S->next->next == NULL) {
		return 0;
	}
	return S->next->next->data;
}

void Pop(LinkSqack* S) {
	LinkSqack* t = S->next;
	S->next = t->next;
	free(t);
}

int main() {
	LinkSqack* S;
	InitSqack(S);
	char e;
	while ((e = cin.get()) != '\n') {
			Push(S, e);
		if (e == ')') {
			if (get(S) == '(') {
				Pop(S);
				Pop(S);
			}
		}
		else if (e == ']') {
			if (get(S) == '[') {
				Pop(S);
				Pop(S);
			}
		}
		else if (e == '}') {
			if (get(S) == '{') {
				Pop(S);
				Pop(S);
			}
		}
	}
	if (S->next == NULL) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;
}