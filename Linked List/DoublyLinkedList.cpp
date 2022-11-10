#include <iostream>
#include <random>
using namespace std;

template <class T>
class DoublyLList {
   private:
    struct Node {
        T data;
        Node *next;
        Node *prev;

        Node(T data) {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    };

    Node *head;
    Node *tail;
    int size;

   public:
    DoublyLList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addTail(T data) {
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

    void addHead(T data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    T getMax() {
        T max = head->data;
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
        T max = getMax();
        for (int exp = 1; max / exp > 0; exp *= 10) {
            DoublyLList *bucket = new DoublyLList[10];
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

    void split(DoublyLList &left, DoublyLList &right) {
        Node *slow = head;
        Node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        left.head = head;
        left.tail = slow;
        right.head = slow->next;
        right.tail = tail;
        slow->next = NULL;
        right.tail->next = NULL;
        left.size = (size + 1) / 2;
        right.size = size / 2;
    }

    DoublyLList merge(const DoublyLList &left, const DoublyLList &right) {
        DoublyLList result;
        Node *leftTemp = left.head;
        Node *rightTemp = right.head;
        while (leftTemp != NULL && rightTemp != NULL) {
            if (leftTemp->data < rightTemp->data) {
                result.addTail(leftTemp->data);
                leftTemp = leftTemp->next;
            } else {
                result.addTail(rightTemp->data);
                rightTemp = rightTemp->next;
            }
        }
        while (leftTemp != NULL) {
            result.addTail(leftTemp->data);
            leftTemp = leftTemp->next;
        }
        while (rightTemp != NULL) {
            result.addTail(rightTemp->data);
            rightTemp = rightTemp->next;
        }
        return result;
    }

    void MergeSort() {
        if (size <= 1) {
            return;
        }
        DoublyLList left, right;
        split(left, right);
        left.MergeSort();
        right.MergeSort();
        DoublyLList result = merge(left, right);
        head = result.head;
        tail = result.tail;
        size = result.size;
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

template <class T>
T random(T min = 1, T max = 99) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<T> dis(min, max);
    return dis(gen);
}

double random(double min = 1, double max = 99) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

int main() {
    DoublyLList<int> list;
    int n = random(5, 15);
    for (int i = 0; i < n; i++) {
        list.addTail(random());
    }
    cout << "Before sorting:\n";
    list.display();

    cout << "After sorting:\n";
    // list.RadixSort();
    list.MergeSort();
    list.display();
}