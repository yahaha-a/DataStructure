#include <iostream>
using namespace std;

typedef struct LinkS {
	int data;
	struct LinkS* next;
}LinkSqack;

void InitSqack(LinkSqack*& S) {
	S = (LinkSqack*)malloc(sizeof(LinkSqack));
	S->next = NULL;
}

void Push1(LinkSqack* S, int e) {
	LinkSqack* t = (LinkSqack*)malloc(sizeof(LinkSqack));
	t->data = e;
	t->next = S->next;
	S->next = t;
	S = t;              
}

void Push2(LinkSqack* S, int e) {
	LinkSqack* t = (LinkSqack*)malloc(sizeof(LinkSqack));
	t->data = e;
	t->next = S->next;
	S->next = t;
}

int pop(LinkSqack* S) {
	LinkSqack* t = S->next;
	S->next = t->next;
	return t->data;
}

bool equal(LinkSqack* S1, LinkSqack* S2) {
	while (S1->next != NULL) {
		if (pop(S1) != pop(S2)) {
			return false;
		}
	}
	return true;
}

int main() {
	LinkSqack* S1, * S2;
	InitSqack(S1);
	InitSqack(S2);
	char e;
	while((e = cin.get()) != '\n') {
		if (e == '(') {
			Push1(S1, 1);
		}
		if (e == '[') {
			Push1(S1, 2);
		}
		if (e == '{') {
			Push1(S1, 3);
		}
		if (e == ')') {
			Push2(S2, 1);
		}
		if (e == ']') {
			Push2(S2, 2);
		}
		if (e == '}') {
			Push2(S2, 3);
		}
	}
	if (equal(S1, S2)) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;
}