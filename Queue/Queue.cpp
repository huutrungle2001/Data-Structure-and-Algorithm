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
class Queue {
   private:
    Node<T> *head;
    Node<T> *tail;
    int size;

   public:
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
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

    T peek() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
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

    T front() {
        return head->data;
    }

    T back() {
        return tail->data;
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
    Queue<Student> queue;

    // Thêm 10 sv vào queue
    queue.enqueue(Student("1001", "Nguyen Van A"));
    queue.enqueue(Student("1002", "Nguyen Van B"));
    queue.enqueue(Student("1003", "Nguyen Van C"));
    queue.enqueue(Student("1004", "Nguyen Van D"));
    queue.enqueue(Student("1005", "Nguyen Van E"));
    queue.enqueue(Student("1006", "Nguyen Van F"));
    queue.enqueue(Student("1007", "Nguyen Van G"));
    queue.enqueue(Student("1008", "Nguyen Van H"));
    queue.enqueue(Student("1009", "Nguyen Van I"));
    queue.enqueue(Student("1010", "Nguyen Van J"));

    // In 10 sv ra, và enqueue lại
    cout << "ID\tStudent Name" << endl;
    for (int i = 0; i < 10; i++) {
        Student student = queue.dequeue();
        cout << student.ID << "\t" << student.name << endl;
        queue.enqueue(student);
    }

    // Xóa 5 sv
    for (int i = 0; i < 5; i++) {
        Student student = queue.dequeue();
    }

    // Thêm 10 sv vào queue
    queue.enqueue(Student("1011", "Nguyen Van K"));
    queue.enqueue(Student("1012", "Nguyen Van L"));
    queue.enqueue(Student("1013", "Nguyen Van M"));
    queue.enqueue(Student("1014", "Nguyen Van N"));
    queue.enqueue(Student("1015", "Nguyen Van O"));
    queue.enqueue(Student("1016", "Nguyen Van P"));
    queue.enqueue(Student("1017", "Nguyen Van Q"));
    queue.enqueue(Student("1018", "Nguyen Van R"));
    queue.enqueue(Student("1019", "Nguyen Van S"));
    queue.enqueue(Student("1020", "Nguyen Van T"));

    // In queue ra
    cout << "ID\tStudent Name" << endl;
    while (!queue.isEmpty()) {
        Student student = queue.dequeue();
        cout << student.ID << "\t" << student.name << endl;
    }

    return 0;
}