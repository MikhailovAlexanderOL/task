// Лабораторная работа №15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdio.h>
using namespace std;
int prime(int a, int b, int *matrix[]) {
	int sum_matrix = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			sum_matrix += matrix[i][j];
		}
	}
	return sum_matrix;
}
int simple(int c, int array[]) {
	int sum_array = 0;

	for (int i = 0; i < c; i++) {
		sum_array += array[i];
	}
	return sum_array;
}
int recursion_array(int *array, int h, int i = 0) {
	if (i >= h) {
		return 0;
	}
	else {
		 return array[i] + recursion_array(array, h, (i + 1));
	}

}
int recursion_matrix(int *matrix[], int q, int m, int i = 0, int sum = 0) {
	if (i >= q ) {
		return 0;
	}
	else {
		for (int j = 0; j < m; j++) {
			sum += matrix[i][j];
		}
		return sum + recursion_matrix(matrix, q, m, (i + 1));
	}
}
  int main () {
	setlocale(LC_ALL, "Rus");
	int len_row, len_column, len;
	printf("Введите количество строк матрицы: ");
	cin >> len_row;
	printf("Введите количество столбцов матрицы: ");
	cin >> len_column;
	printf("Введите количество элементов одномерного массива: ");
	cin >> len;
	int *A = new int[len];
	int **D = new int *[len_row * len_column];
	for (int i = 0; i < len_row; i++) {
		D[i] = new int[len_column];
	}
	printf("Введите элементы матрицы: ");
	for (int i = 0; i < len_row; i++) {
		for (int j = 0; j < len_column; j++) {
			cin >> D[i][j];
		}
	}
	printf("Ведите элементы массива: ");
	for (int i = 0; i < len; i++) {
		cin >> A[i];
	}
	printf("Сумма элементов матрицы: %d\n", prime(len_row, len_column, D));
	printf("Сумма элементов массива: %d\n", simple(len, A));
	printf("Сумма элементов матрицы, найденная с помощью рекурсии: %d\n", recursion_matrix(D, len_row, len_column));
	printf("Сумма элементов массива, найденная с помощью рекурсии: %d", recursion_array(A, len));
	delete[] A;
	for (int i = 0; i < len_row; i++) {
		delete[] D[i];
	}
	delete[] D;
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
