#include <iostream>

using namespace std;

#define MAXSIZE 1000

void CreateArray(int array[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		cin >> array[i];
	}
	array[i] = '\0';
}

void Print(int array[]) {
	while (*array != '\0') {
		cout << *array << ' ';
		array++;
	}
}

void Quick(int array[], int m, int n) {
	int base = array[m];
	int low = m, high = n ;
	while (low < high) {
		while (low < high && array[high] > base) {
			high--;
		}
		if (array[high] < base) {
			array[low] = array[high];
		}
		while (low < high && array[low] < base) {
			low++;
		}
		if (array[low] > base) {
			array[high] = array[low];
		}
	}
	array[low] = base;
	Print(array);
	cout << '\n';
	if (m < low - 1) {
		Quick(array, m, low - 1);

	}
	if (low + 1 < n) {
		Quick(array, low + 1, n);
	}
}

int main() {
	int array[MAXSIZE];
	int n;
	cin >> n;
	CreateArray(array, n);
	Quick(array, 0, n-1);
	return 0;
}
