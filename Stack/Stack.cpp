#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T> *next;

    Node() {
        data = T();
        next = NULL;
    }

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class Stack {
    Node<T> *head;
    int size;

   public:
    Stack() {
        head = NULL;
        size = 0;
    }

    void push(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    T pop() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return T();
        } else {
            Node<T> *temp = head;
            head = head->next;
            T data = temp->data;
            delete temp;
            size--;
            return data;
        }
    }

    T top() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return T();
        } else {
            return head->data;
        }
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};

struct Student {
    string ID;
    string name;

    Student() {
        ID = "";
        name = "";
    }

    Student(string ID, string name) {
        this->ID = ID;
        this->name = name;
    }
};

int main() {
    Stack<Student> stack;
    
    stack.push(Student("1001", "Nguyen Van A"));
    stack.push(Student("1002", "Nguyen Van B"));
    stack.push(Student("1003", "Nguyen Van C"));
    stack.push(Student("1004", "Nguyen Van D"));
    stack.push(Student("1005", "Nguyen Van E"));
    stack.push(Student("1006", "Nguyen Van F"));
    stack.push(Student("1007", "Nguyen Van G"));
    stack.push(Student("1008", "Nguyen Van H"));
    stack.push(Student("1009", "Nguyen Van I"));
    stack.push(Student("1010", "Nguyen Van J"));

    cout << "ID\tStudent Name" << endl;
    while (!stack.isEmpty()) {
        Student student = stack.pop();
        cout << student.ID << "\t" << student.name << endl;
    }
}