#include <iostream>
#include <cstring>
#include <string>
#include <clocale>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;

	cout << "Введите количество книг в библиотеке: ";
	cin >> n;
	cin.ignore();
	char** a = new char* [n];
	char** b = new char* [n];
	int* c = new int[n];
	int* d = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите название книги " << i + 1 << ": ";
		char buffer[100];
		cin.getline(buffer, 100);
		a[i] = new char[strlen(buffer) + 1];
		strcpy(a[i], buffer);
		cout << "Введите автора книги " << i + 1 << ": ";
		cin.getline(buffer, 100);
		b[i] = new char[strlen(buffer) + 1];
		strcpy(b[i], buffer);
		cout << "Введите год издания книги " << i + 1 << ": ";
		cin >> c[i];
		cin.ignore();
		cout << "Введите количество копий книги: " << i + 1 << ": ";
		cin >> d[i];
		cin.ignore();
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[i], a[j]) > 0) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				swap(c[i], c[j]);
				swap(d[i], d[j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << a[i] << " - Автор: " << b[i] << ", Год издания: " << c[i] << ", Количество копий: " << d[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] a[i], b[i];
	}
	delete[] a, b, c, d;

	return 0;
}


