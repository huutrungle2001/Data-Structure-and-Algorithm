#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <class T>
class LinkedList {
    Node<T> *head;
    Node<T> *tail;
    int size;

   public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void add(T data) {
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

    void print() {
        Node<T> *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        Node<T> *prev = NULL;
        Node<T> *curr = head;
        Node<T> *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};