// Лабораторная 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
struct edition {
	string NameOfEdition;
	string Kind;
	int index;
	int price;
};
int main(int argc, const char*argv[]) {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество изданий: ";
	cin >> n;
	int x;
	int k;
	FILE* publications;
	edition* a = new edition[n];
	edition* b = new edition[n];
	edition tmp;
	publications = fopen("C:\\Users\\User\\Desktop\\Editions", "rb+");
	for (int i = 0; i < n; i++) {
		cout << "Введите название издания: ";
		cin >> a[i].NameOfEdition;
		cout << "Выберите вид издания (1 если газета и 0 если журнал): ";
		cin >> x;
		switch (x) {
		case 0:
			a[i].Kind = "magazine";
		case 1:
			a[i].Kind = "newspaper";
			break;
		}
		cout << "Введите индекс: ";
		cin >> a[i].index;
		cout << "Введите цену: ";
		cin >> a[i].price;
	}
	fwrite(&a, sizeof(edition), n, publications);
	fseek(publications, 0, SEEK_SET);
	fread(&b, sizeof(b), n, publications);
	fseek(publications, 0, SEEK_SET);
	fclose(publications);
	int f = 1, i = 0;
	do {
		f = 0;
		for (int j = 0; j < n - 1; ++j) {
			if (b[j + 1].NameOfEdition < b[j].NameOfEdition) {
				tmp = b[j + 1];
				b[j + 1] = b[j];
				b[j] = tmp;
				f = 1;
			}
		}
		i += 1;
	} while (f);
	publications = fopen("C:\\Users\\User\\Desktop\\Editions", "wb");
	fwrite(&b, sizeof(b), n, publications);
	fseek(publications, 0, SEEK_SET);
	fclose(publications);
	printf("Введите количество изданий, которые хотели бы добавить: ");
	cin >> k;
	int h = k + n;
	edition* lastarr = new edition[h];
	for (int i = 0; i < n; i++) {
		lastarr[i].NameOfEdition = b[i].NameOfEdition;
		lastarr[i].Kind = b[i].Kind;
		lastarr[i].index = b[i].index;
		lastarr[i].price = b[i].price;
	}
	for (int i = n; i < h; i++) {
		cout << "Введите название издания: ";
		cin >> lastarr[i].NameOfEdition;
		cout << "Выберите вид издания (1 если газета и 0 если журнал): ";
		cin >> x;
		switch (x) {
		case 0:
			lastarr[i].Kind = "magazine";
		case 1:
			lastarr[i].Kind = "newspaper";
			break;
		}
		cout << "Введите индекс: ";
		cin >> lastarr[i].index;
		cout << "Введите цену: ";
		cin >> lastarr[i].price;
	}
	publications = fopen("C:\\Users\\User\\Desktop\\Editions", "rb+");
	fseek(publications, 0, SEEK_SET);
	for (int i = 0; i < h; i++) {
		cout << lastarr[i].NameOfEdition << " " << lastarr[i].Kind << " " << lastarr[i].index << " " << lastarr[i].price << endl;
	}
	fclose(publications);
	delete[] a;
	delete[] lastarr;
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
