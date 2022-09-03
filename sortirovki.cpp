// Лабораторная работа №16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
unsigned long long compare_counter = 0;
unsigned long long copy_counter = 0;
using namespace std;
int selection_sort(int D[], int a) {
    compare_counter = 0;
    copy_counter = 0;
    int d;
    for (int i = 0; i < a; i++) {
        int imin = i;
        for (int j = i + 1; j < a; j++)
            if (D[j] < D[imin]) {
                imin = j;
            }
        compare_counter++;
        d = D[i];
        D[i] = D[imin];
        D[imin] = d;
        copy_counter += 3;
    }
    return 0;
}
int insertion_sort(int D[], int b) {
    compare_counter = 0;
    copy_counter = 0;
    int d;
    for (int i = 1; i < b; i++) {
        int j = i;
        while ((D[j - 1] > D[j]) && (j >= 1))
            {
            d = D[j];
            D[j] = D[j - 1];
            D[j - 1] = d;
            j--;
            compare_counter += 1;
            copy_counter += 3;
        }
    }
    return 0;
}
struct card{
    char surname[16];
    char name[16];
    char middle_name[16];
    int account_number;
};
void sort(card* arr, int n) {
    card d;
    compare_counter = 0;
    copy_counter = 0;
    for (int i = 1; i < n; i++) {
        int j = i;
        while ((arr[j - 1].account_number < arr[j].account_number) && (j >= 1))
        {
        d = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = d;
        j--;
        compare_counter += 1;
        copy_counter += 3;
        }
    }
}
int bubble_sort(int D[], int c) {
    compare_counter = 0;
    copy_counter = 0;
    int d;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c - 1; j++)
            if (D[j + 1] < D[j]) {
                d = D[j + 1];
                D[j + 1] = D[j];
                D[j] = d;
                copy_counter += 3;
            }
        compare_counter += 1;
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    setlocale(LC_ALL, "Rus");
    int x;
    int n;
    printf("Введите количество элементов массива: ");
        cin >> x;
        int* D = new int[x];
        int* A = new int[x];
        int* B = new int[x];
    printf("Введите элементы массива: ");
    for (int i = 0; i < x; i++) {
        cin >> D[i];
        A[i] = D[i];
        B[i] = D[i];
    }
    printf("Введите количество элементов массива структур: ");
    cin >> n;
    card* arr = new card[n];
    for (int i = 0; i < n; i++) {
        printf("Фамилия: ");
        cin >> arr[i].surname;
        printf("Имя: ");
        cin >> arr[i].name;
        printf("Отчество: ");
        cin >> arr[i].middle_name;
        printf("Номер счёта: ");
        cin >> arr[i].account_number;
    }
    selection_sort(D, x);
    printf("Количство копирований и сравнений: %llu %llu\n", copy_counter, compare_counter);
    insertion_sort(A, x);
    printf("Количство копирований и сравнений: %llu %llu\n", copy_counter, compare_counter);
    bubble_sort(B, x);
    printf("Количство копирований и сравнений: %llu %llu\n", copy_counter, compare_counter);
    printf("Массив отсортированный методом выбора минимального элемента: ");
    for (int i = 0; i < x; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");
    printf("Массив отсортированный методом сортировка вставками: ");
    for (int i = 0; i < x; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Масиив отсортированный пузырьковым методом: ");
    for (int i = 0; i < x; i++) {
        printf("%d ", B[i]);
    }
    sort(arr, n);
    printf("\nОтсортированный массив структур по убыванию номера счёта: \n");
    for (int i = 0; i < n; i++) {
        cout << arr[i].surname << ' ' << arr[i].name << ' ' << arr[i].middle_name << ' ' << arr[i].account_number << endl;
    }
    printf("Количство копирований и сравнений для массива структур: %llu %llu\n", copy_counter, compare_counter);
    delete[]arr;
    delete[]A; 
    delete[]B;
    delete[]D;
}

