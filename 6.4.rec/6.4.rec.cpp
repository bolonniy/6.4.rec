#include <iostream>
#include <Windows.h>
using namespace std;

void SetConsoleEncoding() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

int RecursiveSumNep(int mas[], const int k, int index = 0) {
	if (index >= k) {
		return 0;
	}
	else {
		return mas[index] + RecursiveSumNep(mas, k, index + 2);
	}
}

int RecursiveSumVid(int mas[], const int k, int first, int last) {
	if (first >= last) {
		return 0;
	}
	else {
		return mas[first + 1] + RecursiveSumVid(mas, k, first + 1, last);
	}
}

void PrintArray(int mas[], const int k, int index = 0) {
	if (index >= k) {
		cout << "}" << endl;
	}
	else {
		cout << mas[index] << "; ";
		PrintArray(mas, k, index + 1);
	}
}

int main() {
	SetConsoleEncoding();

	unsigned int Size;
	cout << "¬вед≥ть к≥льк≥сть елемент≥в масива: ";
	cin >> Size;

	int* Arr = new int[Size];
	for (int i = 0; i < Size; i++) {
		cout << "¬вед≥ть " << i << " елемент масива: ";
		cin >> Arr[i];
	}

	cout << endl;
	cout << "Array = { ";
	PrintArray(Arr, Size);

	cout << endl;
	cout << "—ума чисел з непарними номерами: " << RecursiveSumNep(Arr, Size) << endl;

	int first = 0;
	int last = Size - 1;
	while (first < Size && Arr[first] >= 0) {
		first++;
	}
	while (last > first && Arr[last] >= 0) {
		last--;
	}

	cout << "—ума м≥ж першим ≥ останн≥м в≥д'Їмними числами: " << RecursiveSumVid(Arr, Size, first, last) << endl;

	delete[] Arr;
	return 0;
}
