#include <iostream>
using namespace std;
class List {
public:
    List();
    ~List();
    void AddTail(int data);
    void AddHead(int data);
    void Print(int index);
    void Insert(int data, int index);
    int GetElem(int index);
    int GetSize();
    void Delete(int index);
private:
    class Node {
    public:
        Node(int data, Node* pNext = nullptr, Node* pPrev = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
        int data;
        Node* pNext;
        Node* pPrev;
    };
    int size;
    Node* head;
    Node* tail;
};
List::List() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}
List::~List() {
    while (size != 0) {
        Delete(1);
    }
}
int List::GetSize() {
    return size;
}
void List::AddHead(int data) {
    Node* elem = new Node(data);
    if (head != nullptr) {
        head->pPrev = elem;
    }
    if (size == 0) {
        head = tail = elem;
    }
    else {
        head = elem;
    }
    size++;
}
void List::AddTail(int data) {
    Node* elem = new Node(data, nullptr, tail);
    if (tail != nullptr) {
        tail->pNext = elem;
    }
    if (size == 0) {
        tail = head = elem;
    }
    else {
        tail = elem;
    }
    size++;
}
void List::Print(int index) {
    Node* temp;
    if (index <= size / 2) {
        temp = head;
        int i = 1;
        while (i < index) {
            temp = temp->pNext;
            i++;
        }
    }
    else {
        temp = tail;
        int i = 1;
        while (i <= size - index) {
            temp = temp->pPrev;
            i++;
        }
    }
    cout << temp->data;
}
int List::GetElem(int index) {
    Node* temp;
    int i = 1;
    if (index <= size / 2) {
        temp = head;
        while (i < index) {
            temp = temp->pNext;
            i++;
        }
    }
    else {
        temp = tail;
        while (i <= size - index) {
            temp = temp->pPrev;
            i++;
        }
    }
    return temp->data;
}
void List::Insert(int data, int index) {
    if (index == size + 1) {
        AddTail(data);
        return;
    }
    if (index == 1) {
        AddHead(data);
        return;
    }
    Node* insert = head;
    int i = 1;
    while (i < index) {
        insert = insert->pNext;
        i++;
    }
    Node* prevInsert = insert->pPrev;
    Node* temp = new Node(data);
    if (prevInsert != nullptr && size != 1) {
        prevInsert->pNext = temp;
    }
    temp->pNext = insert;
    temp->pPrev = prevInsert;
    insert->pPrev = temp;
    size++;
}
void List::Delete(int index) {
    int i = 1;
    Node* Del = head;
    while (i < index) {
        Del = Del->pNext;
        i++;
    }
    Node* prevDel = Del->pPrev;
    Node* afterDel = Del->pNext;
    if (prevDel != nullptr && size != 1) {
        prevDel->pNext = afterDel;
    }
    if (afterDel != nullptr && size != 1) {
        afterDel->pPrev = prevDel;
    }
    if (index == 1) {
        head = afterDel;
    }
    if (index == size) {
        tail = prevDel;
    }
    delete Del;
    size--;
}

int main(int argc, const char* argv[]) {
    setlocale(LC_ALL, "Rus");
    int n;
    List spisok;
    cout << "Введите количсество элементов: ";
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        spisok.AddTail(x);
    }
    for (int i = 0; i < n; i++) {
        if (spisok.GetElem(i+1) < 0) {
            spisok.Delete(i+1);
        }
    }
    spisok.Insert(4, 3);
    cout << '\n' <<  "Результат: " << endl;
    for (int i = 0; i < spisok.GetSize(); i++) {
        spisok.Print(i+1);
        cout << '\t';
    }
}