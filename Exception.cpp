// Лабораторная номер 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>

using namespace std;
class file_open_error {
public:
	void print() {
		cout << "Ошибка при открытии файла ";
	}
};
class file_read_error {
public:
	void print() {
		cout << "Ошибка при чтении файла ";
	}
};
class file_write_error {
public:
	void print() {
		cout << "Ошибка при написании файла ";
	}
};
class MyException {
public:
	MyException(int k, int z, int *a) {
		this->indexMin = k;
		this->indexMax = z;
		this->dataPointer = a;
	}
	void Founder() {
		ofstream x("C:\\Users\\User\\Desktop\\Отсортированныечисла.txt", ios::out);
		for (int i = indexMin + 1; i < indexMax; i++) {
			x << dataPointer[i] << " ";
		}
		x.close();
	}
private:
	int indexMin;
	int indexMax;
	int* dataPointer;
};
class ForeignException {
public:
	ForeignException(int k, int z, int* a) {
		this->indexMin = k;
		this->indexMax = z;
		this->dataPointer = a;
	}
	void Founderx() {
		ofstream x("C:\\Users\\User\\Desktop\\Отсортированныечисла.txt", ios::out);
		for (int i = indexMax + 1; i < indexMin; i++) {
			x << dataPointer[i] << " ";
		}
		x.close();
	}
private:
	int indexMin;
	int indexMax;
	int* dataPointer;
};
void input(int n) {
	string name;
	int* L = new int[n];
	ofstream f("C:\\Users\\User\\Desktop\\Числа.txt", ios::out);
		printf("Введите числа: ");
		for (int i = 0; i < n; i++) {
			cin >> L[i];
			if (L[i] == false) {
				throw file_write_error();
			}
		}
		for (int i = 0; i < n; i++) {
			f << L[i] << '\t';
		}
	f.close();
	delete[] L;
}
void Class(int n) {
	int* A = new int[n];
	int min = 1000;
	int max = -1000;
	int x = 0;
	int h = 0;
	ifstream f("C:\\Users\\User\\Desktop\\Числа.txt", ios::in);
	for (int i = 0; i < n; i++) {
		f >> A[i];
	}
	for (int i = 0; i < n; i++) {
		if (A[i] < min) {
			min = A[i];
			x = i;
		}
		if (A[i] > max) {
			max = A[i];
			h = i;
		}
	}
	if (h > x) {
		throw MyException( x, h, A);
	}
	if (x > h) {
		throw ForeignException(x, h, A);
	}
	delete []A;
}

int main(int argc, const char argv[]) {
	setlocale(LC_ALL, "rus");
	int n;
	printf("Введите количество чисел: ");
	cin >> n;
	try {
		input(n);
	}
	catch (file_open_error& ex) {
		ex.print();
	}
	catch (file_write_error &ex) {
		ex.print();
	}
	try {
		Class(n);
	}
	catch (MyException &ex) {
		 ex.Founder();
	}
	catch (ForeignException &ex) {
		 ex.Founderx();
	}
	catch (file_read_error &ex) {
		ex.print();
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
