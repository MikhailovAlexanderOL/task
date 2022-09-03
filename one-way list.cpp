#include <iostream>
using namespace std;
class List {
public:
	List();
	~List();
	char pop_front();
	void push_front(char data);
private:
	class Node{
	public:
		Node *pNext;
		char data;
		Node(char data , Node * pNext = nullptr){
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node* head;
};
List::List(){
	size = 0;
	head = nullptr;
}
List::~List(){
}
char List::pop_front() {
	char variable;
	Node* temp = head;
	variable = temp->data;
	head = head->pNext;
	delete temp;
	size--;
	return variable;
}
void List::push_front(char data) {
	head = new Node(data, head);
	size++;
}

int main(int argc, const char *argv[]) {
	setlocale(LC_ALL, "Rus");
	List spisok;
	char n;
	cout << "Введите скобочную последовательность: ";
	while (cin >> n && n != '/') {
		if (n == '{' || n == '(' || n == '[') {
			spisok.push_front(n);
			cout << n;
		}
		if (n == '}' || n == ')' || n == ']') {
			switch (spisok.pop_front()) {
			case '{':
				if (n == '}') {
					cout << n;
				}
				else {
					break;
				}
			case '(':
				if (n == ')') {
					cout << n;
				}
				else {
					break;
				}
			case '[':
				if (n == ']') {
					cout << n;
				}
				else {
					break;
				}
			}
		}
	}
}