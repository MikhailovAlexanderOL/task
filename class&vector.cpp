// Лабораторная 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
const char DefaultVehicleName[] = "Untyped vehicle";
const char DefaultCoachName[] = "Default Coach";
const char DefaultAutomobileName[] = "Default Automobile";
const char DefaultAeroplaneName[] = "Default Aeroplane";
const double DefaultVehicleSpeed = -1.;
const double DefaultCoachSpeed = 10.;
const double DefaultAutomobileSpeed = 100.;
const double DefaultAeroplaneSpeed = 500.;
const double DefaultTimeToBoot = 0.01;
template <class Type>
class MyVector {
public:
    MyVector();
    MyVector(const MyVector&);
    ~MyVector();
    void PushBack(Type);
    Type& operator[] (int) const;
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
    Type* z = new Type[newCapacity];
    for (int i = 0; i < this->capacity; ++i) {
        z[i] = this->dataPointer[i];
    }
    delete[] this->dataPointer;
    this->dataPointer = z;
    this->capacity = newCapacity;
}

template <typename Type>
Type& MyVector<Type>::operator[](const int index) const {
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
void MySwap(MyType& v1, MyType& v2) {

    MyType v3 = v1;
    v1 = v2;
    v2 = v3;
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
class Vehicle {
public:
    virtual double GetSpeed() const = 0;
    Vehicle() : totalDistance(0), totalTime(0), baseSpeed(DefaultVehicleSpeed) {
        SetName(DefaultVehicleName);
    }
    Vehicle(const char inNameCString[], double inBaseSpeed, int inBasePrice) : totalDistance(0),
        totalTime(0), baseSpeed(inBaseSpeed) {
        SetName(inNameCString);
    }
    virtual ~Vehicle() {
    }
    void SetSpeed(double inBaseSpeed) {
        baseSpeed = inBaseSpeed;
    }
    const char* const GetName() const {
        return nameCString;
    }
    double GetBaseSpeed() const {
        return baseSpeed;
    }
    double GetTotalDistance() const {
        return totalDistance;
    }
    double GetTotalTime() const {
        return totalTime;
    }
    virtual bool MakeTrip(double distance) = 0;
    bool operator< (Vehicle& rhs) const {
        if (GetSpeed() < rhs.GetSpeed()) {
            return true;
        }
        return false;
    }
    static const int MAX_NAME_LENGTH = 50;
    void SetName(const char inNameCString[]) {
        int i = 0;
        for (i = 0; (inNameCString[i] != 0) && (i < MAX_NAME_LENGTH); ++i) {
            nameCString[i] = inNameCString[i];
        }
        nameCString[i] = 0;
    }
protected:
    double totalDistance;
    double totalTime;
private:
    char nameCString[MAX_NAME_LENGTH];
    double baseSpeed;
};
class Computer {
public:
    Computer() : baseTimeToBoot(DefaultTimeToBoot) {}
    double GetTimeToBoot() { // возвращает время загрузки компьютера
        return baseTimeToBoot;
    }
protected:
    double baseTimeToBoot;
};
class Aeroplane : private Computer, public Vehicle {
public:
    void ComputerUpdate(double newTimeToBoot);
    Aeroplane(const char inNameCString[] = DefaultAeroplaneName, double inBaseSpeed = DefaultAeroplaneSpeed, int inBasePrice = 0) {
        SetSpeed(inBaseSpeed);
        SetName(inNameCString);
    };
    virtual double GetSpeed() const {
        return GetBaseSpeed();
    }
    virtual bool MakeTrip(double distanceOfTrip) {
        double timeOfTrip = distanceOfTrip / GetSpeed() + GetTimeToBoot();
        if (timeSinceLastRepair + timeOfTrip > MAX_FLY_TIME) {
            return false;
        }
        timeSinceLastRepair += timeOfTrip;
        totalDistance += distanceOfTrip;
        totalTime += timeOfTrip;
        return true;
    }
    void Repair() {
        timeSinceLastRepair = 0;
    }
    double GetTimeSinceLastRepair() const {
        return timeSinceLastRepair;
    }
    static const int MAX_FLY_TIME = 100;
private:
    double timeSinceLastRepair = 0;
};
void Aeroplane::ComputerUpdate(double newTimeToBoot) {
    baseTimeToBoot = newTimeToBoot;
}

class Coach :public Vehicle {
public:
    Coach(const char inNameCString[] = DefaultCoachName, double inBaseSpeed = DefaultCoachSpeed, int inBasePrice = 0) {
        SetSpeed(inBaseSpeed);
        SetName(inNameCString);
    };
    double GetSpeed() const {
        return GetBaseSpeed()* exp(-totalTime / 500.);
    }
    static const int MAX_DISTANCE = 100;
    bool MakeTrip(double distanceOfTrip) {
        double timeOfTrip = distanceOfTrip / GetSpeed();
        if ( distanceOfTrip > MAX_DISTANCE) {
            return false;
        } 
        totalDistance += distanceOfTrip;
        totalTime += timeOfTrip;
        return true;
    }
};
class Automobile : public Vehicle {
public:
    Automobile(const char inNameCString[] = DefaultAutomobileName, double inBaseSpeed = DefaultAutomobileSpeed, int inBasePrice = 0) {
        SetSpeed(inBaseSpeed);
        SetName(inNameCString);
    };
    double GetSpeed() const override{
        return GetBaseSpeed() * exp(-totalTime / 500.);
    }
    bool MakeTrip(double distanceOfTrip) {
        double timeOfTrip = distanceOfTrip / GetSpeed();
        totalDistance += distanceOfTrip;
        totalTime += timeOfTrip;
        return true;
    }
};
void CommitRandomTrips(MyVector<Vehicle*>& vehicles) {
    for (int i = 0; i < vehicles.Length(); ++i) {
        double randomDistance = double(rand() % 20001) / 10.;
        vehicles[i]->MakeTrip(randomDistance);
    }
}
void DisplayVehicles(const MyVector<Vehicle*>& vehicles) {
    printf("%s \t%14s\t%7s\t%6s\n", "Name", "Speed", "Dist", "Time");
    for (int i = 0; i < vehicles.Length(); ++i) {
        printf("%s \t%6.2lf\t%7.2lf\t%6.2lf\n", vehicles[i]->GetName(), vehicles[i]->GetSpeed(),
            vehicles[i]->GetTotalDistance(), vehicles[i]->GetTotalTime());
    }
}
template <class ArrayType, class LessFunctionType>
int FindMinimumIndex(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) {
    int minimumIndex = beginIndex;
    for (int element_number = beginIndex + 1; element_number <= endIndex; ++element_number) {
        if (LessFunction(data_array[element_number], data_array[minimumIndex])) {
            minimumIndex = element_number;
        }
    }
    return minimumIndex;
}
template <class ArrayType, class LessFunctionType>
void SelectionSort(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) {
    for (int element_number = beginIndex; element_number < endIndex; ++element_number) {
        int minimumIndex = FindMinimumIndex(data_array, element_number, endIndex, LessFunction);
        MySwap(data_array[minimumIndex], data_array[element_number]);
    }
}
template<class ArrayType, class LessFunctionType>
void InsertionSort(ArrayType& data_array, int n, LessFunctionType LessFunction) {
    for (int i = 1; i < n; ++i) {
        int j = i;
        while ((LessFunction(data_array[j], data_array[j-1])) && (j>=1)) {
            MySwap(data_array[j], data_array[j-1]);
            j--;
        }
    }
}
bool CompareDefault(Vehicle* lhs, Vehicle* rhs) {
    return *lhs < *rhs;
}
bool CompareTime(Vehicle* lhs, Vehicle* rhs) {
    return lhs->GetTotalTime() < rhs->GetTotalTime();
}
bool CompareDist(Vehicle* khs, Vehicle* vhs) {
    return khs->GetTotalDistance() < vhs->GetTotalDistance();
}



int main(int argc, const char*argv[]) {
    setlocale(LC_ALL, "Rus");
    srand(0);
    MyVector<Coach> coaches;
    MyVector<Automobile> automobiles;
    MyVector<Aeroplane> aeroplanes;
    coaches.PushBack(Coach("Coach 1", 9.));
    coaches.PushBack(Coach("Coach 2", 11.));
    coaches.PushBack(Coach("Coach 3", 10.));
    coaches.PushBack(Coach("Coach 4", 9.5));
    coaches.PushBack(Coach("Coach 5"));
    automobiles.PushBack(Automobile("Automobile 1"));
    automobiles.PushBack(Automobile("Automobile 2", 90.));
    automobiles.PushBack(Automobile("Automobile 3", 120.));
    automobiles.PushBack(Automobile("Automobile 4", 150.));
    aeroplanes.PushBack(Aeroplane("Aeroplane 1", 1030.));
    aeroplanes.PushBack(Aeroplane("Aeroplane 2", 560.));
    aeroplanes.PushBack(Aeroplane("Aeroplane 3", 2200.));
    MyVector<Vehicle *> coachPointers;
    MyVector<Vehicle *> automobilePointers;
    MyVector<Vehicle *> aeroplanePointers;
    for (int i = 0; i < coaches.Length(); ++i) {
         coachPointers.PushBack(&coaches[i]);
    }
    for (int i = 0; i < automobiles.Length(); ++i) {
        automobilePointers.PushBack(&automobiles[i]);
    }
    for (int i = 0; i < aeroplanes.Length(); ++i) {
        aeroplanePointers.PushBack(&aeroplanes[i]);
    }
    MyVector<Vehicle*> vehiclePointers = coachPointers + automobilePointers + aeroplanePointers;
    printf("Вывод исходных данных:\n");
    CommitRandomTrips(vehiclePointers);
    DisplayVehicles(vehiclePointers);
    printf("Вывод данных, отсортированных по скорости\nс помощью сортировки вставками:\n");
    InsertionSort(vehiclePointers, 12, CompareDefault);
    DisplayVehicles(vehiclePointers);
    printf("Вывод данных, отсортированных по времени\nс помощью сортировки поиска минимального значения:\n");
    FindMinimumIndex(vehiclePointers, 0, 11, CompareTime);
    SelectionSort(vehiclePointers, 0, 11, CompareTime);
    DisplayVehicles(vehiclePointers);
    printf("Вывод данных, отсортированных по дистанции\nс помощью сортировки вставками:\n");
    InsertionSort(vehiclePointers, 12, CompareDist);
    DisplayVehicles(vehiclePointers);
}

