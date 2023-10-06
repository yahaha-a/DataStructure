#include <iostream>
using namespace std;

#define MAXSIZE 100

union Data {
	char datac;
	int datai;
};

typedef struct LinkS {
	Data data;
	struct LinkS* next;
}LinkStNodeC, LinkStNodeI;

void InitLink(struct LinkS*& S) {
	S = (struct LinkS*)malloc(sizeof(struct LinkS));
	S->next = NULL;
}

void DestoryLink(struct LinkS* S) {
	struct LinkS* pre = S, * p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool EmptyLink(struct LinkS* S) {
	return (S->next == NULL);
}

bool Push(struct LinkS* S, Data data) {
	struct LinkS* t;
	InitLink(t);
	t->data = data;
	t->next = S->next;
	S->next = t;
	return true;
}

bool Pop(struct LinkS* S, Data& data) {
	if (S->next == NULL) {
		return false;
	}
	struct LinkS* t;
	t = S->next;
	S->next = t->next;
	data = t->data;
	free(t);
	return true;
}

bool GetTop(struct LinkS* S, Data& data) {
	if (S->next == NULL) {
		return false;
	}
	data = S->next->data;
	return true;
}

void CreateArry(char exp[]) {
	while ((*exp = cin.get()) != '\n') {
		if (*exp == '^') {
			char e = *(exp-1);
			exp--;
			int i = 0;
			i = cin.get() - '0';
			if (i == 0) {
				*exp = '1';
			}
			for (int j = 1; j < i; j++) {
				exp++;
				*exp = '*';
				exp++;
				*exp = e;
			}
		}
		exp++;
	}
	*exp = '\0';
}

void ForArry(char exp[]) {
	while (*exp != '\0') {
		cout << *exp << ' ';
		exp++;
	}
}

void trans(char postexp[], char exp[]) {
	Data data1;
	Data data2;
	LinkStNodeC* Optr;
	InitLink(Optr);
	while (*exp != '\0') {
		data1.datac = *exp;
		switch (*exp) {
		case '(':
			Push(Optr, data1);
			exp++;
			break;
		case ')':
			Pop(Optr, data2);
			while (data2.datac != '(') {
				*postexp = data2.datac;
				postexp++;
				Pop(Optr, data2);
			}
			exp++;
			break;
		case '+':
		case '-':
			while (!EmptyLink(Optr)) {
				GetTop(Optr, data2);
				if (data2.datac != '(') {
					*postexp = data2.datac;
					postexp++;
					Pop(Optr, data2);
				}
				else {
					break;
				}
			}
			Push(Optr, data1);
			exp++;
			break;
		case '*':
		case '/':
			while (!EmptyLink(Optr)) {
				GetTop(Optr, data2);
				if (data2.datac == '*' || data2.datac == '/') {
					*postexp = data2.datac;
					postexp++;
					Pop(Optr, data2);
				}
				else {
					break;
				}
			}
			Push(Optr, data1);
			exp++;
			break;
		default:
			while ((*exp > '0' || *exp == '0') && (*exp < '9' || *exp == '9')) {
				*postexp = *exp;
				exp++;
				postexp++;
			}
			*postexp = '#';
			postexp++;
		}
	}
	while (!EmptyLink(Optr)) {
		Pop(Optr, data2);
		*postexp = data2.datac;
		postexp++;
	}
	*postexp = '\0';
	DestoryLink(Optr);
}

double compvalue(char postexp[]) {
	Data datat, data1, data2, data;
	LinkStNodeI* Opnd;
	InitLink(Opnd);
	while (*postexp != '\0') {
		switch (*postexp) {
		case '-':
			Pop(Opnd, data1);
			Pop(Opnd, data2);
			data.datai = data2.datai - data1.datai;
			Push(Opnd, data);
			break;
		case '+':
			Pop(Opnd, data1);
			Pop(Opnd, data2);
			data.datai = data2.datai + data1.datai;
			Push(Opnd, data);
			break;
		case '*':
			Pop(Opnd, data1);
			Pop(Opnd, data2);
			data.datai = data2.datai * data1.datai;
			Push(Opnd, data);
			break;
		case '/':
			Pop(Opnd, data1);
			Pop(Opnd, data2);
			data.datai = data2.datai / data1.datai;
			Push(Opnd, data);
			break;
		default:
			data.datai = 0;;
			while ((*postexp > '0' || *postexp == '0') && (*postexp < '9' || *postexp == '9')) {
				data.datai = data.datai * 10 + *postexp - '0';
				postexp++;
			}
			Push(Opnd, data);
			break;
		}
		postexp++;
	}
	GetTop(Opnd, datat);
	DestoryLink(Opnd);
	return datat.datai;
}

int main() {
	char exp[MAXSIZE];
	char postexp[MAXSIZE];
	CreateArry(exp);
	trans(postexp, exp);
	cout << compvalue(postexp);
	return 0;
}