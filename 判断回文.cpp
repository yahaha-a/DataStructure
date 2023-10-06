#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 100

typedef struct {
	char data[MAXSIZE];
	int top;
}Sqack;

void InitSqack(Sqack*& S) {
	S = (Sqack*)malloc(sizeof(Sqack));
	S->top = -1;
}

void CreateSqack(Sqack* S, char num[], int i) {
	while (i) {
		S->top++;
		S->data[S->top] = num[S->top];
		i--;
	}
}

char Pop(Sqack* S) {
	char e = S->data[S->top];
	S->top--;
	return e;
}

bool huiwen(Sqack* S, char num[]) {
	int i = 0;
	while (S->top) {
		if (Pop(S) != num[i]) {
			return false;
		}
		i++;
	}
	return true;
}

int main() {
	Sqack* S;
	string a;
	char num[MAXSIZE];
	getline(cin, a);
	int i = 0;
	while (a[i] != '\0') {
		num[i] = a[i];
		i++;
	}
	num[i] = '\0';
	InitSqack(S);
	CreateSqack(S, num, i);
	for (int j = 0; j <= i; j++) {
		cout << num[j];
	}
	if (huiwen(S, num)) {
		cout << "是回文。";
	}
	else {
		cout << "不是回文。";
	}
	return 0;
}