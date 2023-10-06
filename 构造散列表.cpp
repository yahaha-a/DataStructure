#include <iostream>

using namespace std;

#define MAXSIZE 18

typedef struct {
	int key;
	int count;
	int pos;
}Haxi;

void InitHaxi(Haxi* h[]) {
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		h[i] = (Haxi*)malloc(sizeof(Haxi));
		h[i]->key = -1;
		h[i]->count = h[i]->pos = 0;
	}
}

void CreateArray(int array[]) {
	int n, i = 0;
	cin >> n;
	for (i; i < n; i++) {
		cin >> array[i];
	}
	array[i] = '\0';
}

void CreateHaxi(Haxi* h[], int m, int p, int di, int array[]) {
	int temp = 0;
	while (*array != '\0') {
		temp = *array % p;
		while (h[temp]->key != -1) {
			temp = (temp + di + m) % m;
		}
		h[temp]->count = *array;
		h[temp]->pos = temp;
		h[temp]->key = 0;
		array++;
	}
}

void Print(Haxi* h[], int array[]) {
	while (*array != '\0') {
		for (int i = 0; i < MAXSIZE; i++) {
			if (h[i]->count == *array) {
				cout << h[i]->count << " pos: " << h[i]->pos << '\n';
			}
		}
		array++;
	}
}

int main() {
	Haxi* h[MAXSIZE];
	InitHaxi(h);
	int array[MAXSIZE];
	CreateArray(array);
	int m = 18, p = 17, di = 5;
	CreateHaxi(h, m, p, di, array);
	Print(h, array);
	return 0;
}