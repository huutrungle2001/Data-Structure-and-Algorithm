#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} DList;

Node *newNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

DList *newDList() {
    DList *new = (DList *)malloc(sizeof(DList));
    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    return new;
}

void addTail(DList *list, int data) {
    Node *node = newNode(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->size++;
}

void addHead(DList *list, int data) {
    Node *node = newNode(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

void addAt(DList *list, int data, int index) {
    if (index < 0 || index > list->size) {
        printf("Index out of range\n");
        return;
    }

    if (index == 0) {
        addHead(list, data);
    } else if (index == list->size) {
        addTail(list, data);
    } else {
        Node *node = newNode(data);
        Node *temp = list->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
        list->size++;
    }
}

void removeHead(DList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
    list->size--;
}

void removeTail(DList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
    list->size--;
}

void removeAt(DList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of range\n");
        return;
    }

    if (index == 0) {
        removeHead(list);
    } else if (index == list->size - 1) {
        removeTail(list);
    } else {
        Node *temp = list->head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        list->size--;
    }
}

int getMax(DList *list) {
    int max = list->head->data;
    Node *temp = list->head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void RadixSort(DList *list) {
    int max = getMax(list);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        DList *bucket[10];
        for (int i = 0; i < 10; i++) {
            bucket[i] = newDList();
        }

        Node *temp = list->head;
        while (temp != NULL) {
            int index = (temp->data / exp) % 10;
            addTail(bucket[index], temp->data);
            temp = temp->next;
        }

        int index = 0;
        temp = list->head;
        while (temp != NULL) {
            while (bucket[index]->size == 0) {
                index++;
            }
            temp->data = bucket[index]->head->data;
            bucket[index]->head = bucket[index]->head->next;
            bucket[index]->size--;
            temp = temp->next;
        }
    }
}

void splitList(DList *list, DList *left, DList *right) {
    Node *temp = list->head;
    for (int i = 0; i < list->size / 2; i++) {
        addTail(left, temp->data);
        temp = temp->next;
    }
    while (temp != NULL) {
        addTail(right, temp->data);
        temp = temp->next;
    }
}

DList *mergeList(DList *left, DList *right) {
    DList *result = newDList();
    Node *itLeft = left->head;
    Node *itRight = right->head;

    // Two pointer technique
    while (itLeft != NULL && itRight != NULL) {
        if (itLeft->data < itRight->data) {
            addTail(result, itLeft->data);
            itLeft = itLeft->next;
        } else {
            addTail(result, itRight->data);
            itRight = itRight->next;
        }
    }
    while (itLeft != NULL) {
        addTail(result, itLeft->data);
        itLeft = itLeft->next;
    }
    while (itRight != NULL) {
        addTail(result, itRight->data);
        itRight = itRight->next;
    }
    return result;
}

void mergeSort(DList *list) {
    if (list->size <= 1) {
        return;
    }

    DList *left = newDList();
    DList *right = newDList();
    splitList(list, left, right);

    mergeSort(left);
    mergeSort(right);

    DList *result = mergeList(left, right);
    list->head = result->head;
    list->tail = result->tail;
    list->size = result->size;
}

void display(DList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseDisplay(DList *list) {
    Node *temp = list->tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));
    DList *list = newDList();
    for (int i = 0; i < 10; i++) {
        addTail(list, random(0, 100));
    }
    display(list);
    // RadixSort(list);
    mergeSort(list);
    display(list);
    return 0;
}