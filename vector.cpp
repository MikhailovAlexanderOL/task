// Лабораторная работа №17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <class Type>
class MyVector {
public:
    MyVector();
    MyVector(const MyVector&);
    ~MyVector();
    void PushBack(Type);
    const Type& operator[] (int) const;
    MyVector& operator= (const MyVector&);
    bool IsEmpty() const;
    int Length() const;
    int Capacity() const;
    MyVector<Type> operator+ (const MyVector&);

private:
    int length;
    int capacity;
    Type* dataPointer;
    void UpCapacity(int);
};

template <typename Type>
MyVector<Type>::MyVector() {
    this->length = 0;
    this->capacity = 1;
    this->dataPointer = new Type[1];
}
template <typename Type>
MyVector<Type>::~MyVector() {
    delete[] this->dataPointer;
}

template <typename Type>
void MyVector<Type>::PushBack(Type newElement) {
    this->length++;
    if (this->length > this->capacity)
        UpCapacity(2 * this->capacity);
    this->dataPointer[this->length - 1] = newElement;
}

template <typename Type>
bool MyVector<Type>::IsEmpty() const {
    if (this->length == 0) {
        return true;
    }
    else
        return false;
}

template <typename Type>
int MyVector<Type>::Length() const {
    return this->length;
}

template <typename Type>
int MyVector<Type>::Capacity() const {
    return this->capacity;
}
template <typename Type>
void MyVector<Type>::UpCapacity(int newCapacity) {
    Type* tmp = new Type[newCapacity];
    for (int i = 0; i < this->capacity; ++i)
        tmp[i] = this->dataPointer[i];
    delete[] this->dataPointer;
    this->dataPointer = tmp;
    this->capacity = newCapacity;
}


template <typename Type>
const Type& MyVector<Type>::operator[](const int index) const {
    return *(dataPointer + index);
}

template <typename Type>
MyVector<Type>::MyVector(const MyVector<Type>& rhs) {
    this->length = rhs.Length();
    this->capacity = rhs.Capacity();
    this->dataPointer = new Type[this->capacity];
    for (int i = 0; i < this->capacity; ++i)
        this->dataPointer[i] = rhs[i];
}

template <typename Type>
MyVector<Type>& MyVector<Type>::operator=(const MyVector<Type>& rhs) {
    MyVector<Type> tmp(rhs);
    if (this->capacity != 0)
        delete[] this->dataPointer;
    this->length = tmp.Length();
    this->capacity = tmp.Capacity();
    this->dataPointer = new Type[this->capacity];
    for (int i = 0; i < this->capacity; ++i)
        this->dataPointer[i] = tmp[i];
    return *this;
}

template<class Type>
MyVector<Type> MyVector<Type>::operator+(const MyVector& rhs) {
    MyVector<Type> res = *this;
    for (int i = 0; i < rhs.Length(); ++i)
        res.PushBack(rhs[i]);
    return res;
}

template <class MyType>
void MySwap(MyType& element1, MyType& element2) {
    MyType element3 = element1;
    element1 = element2;
    element2 = element3;
}
template <class Type>
void InputMyVector(MyVector<Type>& inVector, int n) {
    for (int i = 0; i < n; ++i) {
        Type tmp;
        std::cin >> tmp;
        inVector.PushBack(tmp);
    }
}
template <class Type>
void OutputMyVector(const MyVector<Type>& outVector) {
    for (size_t i = 0; i < outVector.Length(); ++i)
        std::cout << outVector[i] << ' ';
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    MyVector<int> v1, v2;
    int len = 0;
    int n;
    int* Arr = new int[100];
    std::cout << "Введите длину 1 вектора:";
    std::cin >> len;
    std::cout << "Введите 1 вектор: ";
    InputMyVector(v1, len);
    std::cout << "Введите длину 2 вектора:";
    std::cin >> len;
    std::cout << "Введите 2 вектор: ";
    InputMyVector(v2, len);
    std::cout << "Введите эелемент, больше которого хотите вывести элементы: \n ";
    std::cin >> n;
    //for (int i = 0; i < 3; i++) {
     //   std::cout << Arr[i] << ' ';
    //}
    MyVector<int> v3;
    v3 = v1 + v2;
    std::cout << "Результат сложения двух векторов:\n";
    OutputMyVector(v3);
    return 0;
}