#include <iostream>
#include <random>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

struct DLinkedList {
    Node *head;
    Node *tail;
    int size;

    DLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addTail(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int getMax() {
        int max = head->data;
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }

    void RadixSort() {
        int max = getMax();
        for (int exp = 1; max / exp > 0; exp *= 10) {
            DLinkedList *bucket = new DLinkedList[10];
            Node *temp = head;
            while (temp != NULL) {
                int index = (temp->data / exp) % 10;
                bucket[index].addTail(temp->data);
                temp = temp->next;
            }
            int index = 0;
            temp = head;
            while (temp != NULL) {
                while (bucket[index].size == 0) {
                    index++;
                }
                temp->data = bucket[index].head->data;
                bucket[index].head = bucket[index].head->next;
                bucket[index].size--;
                temp = temp->next;
            }
        }
    }

    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int random(int min = 1, int max = 99) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    DLinkedList list;
    int n = random(5, 15);
    for (int i = 0; i < n; i++) {
        list.addTail(random());
    }
    cout << "Before sorting:\n";
    list.display();

    cout << "After sorting:\n";
    list.RadixSort();
    list.display();
}