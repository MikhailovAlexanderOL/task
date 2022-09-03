// Лаба2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
struct Card {
	string surname;
	int* B = new int [5];
	int max = 0;
};
void input(int n) {
	string name;
	int* L = new int[5];
	ofstream f("C:\\Users\\User\\Desktop\\Фигуристы.txt", ios::out);
	for (int i = 0; i < n; i++) {
		printf("Введите имя фигуристки: ");
		cin >> name;
		f << name << '\t';
		printf("Введите оценки судей: ");
		for (int i = 0; i < 5; i++) {
			cin >> L[i];
		}
		for (int i = 0; i < 5; i++) {
			f << L[i] << '\t';
		}
		f << '\n';
	}
	f.close();
}
void read(Card *A, int n) {
	int d;
	string name;
	ifstream f("C:\\Users\\User\\Desktop\\Фигуристы.txt", ios::in);
	ofstream x("C:\\Users\\User\\Desktop\\Топ.txt", ios::out);
	while (!f.eof()) {
		for (int i = 0; i < n; i++) {
			f >> A[i].surname;
			A[i].max = 0;
			for (int j = 0; j < 5; j++) {
				f >> A[i].B[j];
				A[i].max += A[i].B[j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int j = i;
			while ((A[j - 1].max < A[j].max) && (j >= 1))
			{
				d = A[j].max;
				name = A[j].surname;
				A[j].max = A[j - 1].max;
				A[j].surname = A[j - 1].surname;
				A[j - 1].max = d;
				A[j - 1].surname = name;
				j--;
			}
	}
	for (int i = 0; i < 3; i++) {
		x << A[i].surname << " " << A[i].max << '\n';
	}
	f.close();
	x.close();
}
int main(int argc, const char *argv[]) {
	setlocale(LC_ALL, "Rus");
	int n;
	printf("Введите количество фигуристов: ");
	cin >> n;
	input(n);
	Card* A = new Card[n];
	read(A, n);
}

