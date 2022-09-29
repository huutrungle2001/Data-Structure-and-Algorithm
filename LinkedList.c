#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList newList() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

void addHead(LinkedList *list, int data) {
    Node *node = newNode(data);
    if (list->head == NULL) {
        list->head = list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

void addTail(LinkedList *list, int data) {
    Node *node = newNode(data);
    if (list->head == NULL) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void addAt(LinkedList *list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    if (position == 0) {
        addHead(list, data);
        return;
    }

    if (position == list->size) {
        addTail(list, data);
        return;
    }

    Node *node = newNode(data);
    Node *it = list->head;
    while (position-- > 1) {
        it = it->next;
    }
    node->next = it->next;
    it->next = node;
    list->size++;
}

void deleteHead(LinkedList *list) {
    if (list->head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    Node *node = list->head;
    list->head = list->head->next;
    free(node);
    list->size--;
}

void deleteTail(LinkedList *list) {
    if (list->head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    Node *it = list->head;
    while (it->next != list->tail) {
        it = it->next;
    }
    free(list->tail);
    list->tail = it;
    list->tail->next = NULL;
    list->size--;
}

void deleteAt(LinkedList *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    if (position == 0) {
        deleteHead(list);
        return;
    }

    if (position == list->size - 1) {
        deleteTail(list);
        return;
    }

    Node *it = list->head;
    while (position-- > 1) {
        it = it->next;
    }

    Node *node = it->next;
    it->next = it->next->next;
    free(node);
    list->size--;
}

void displayList(LinkedList list) {
    if (list.head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *it = list.head;
    while (it != list.tail->next) {
        printf("%d ", it->data);
        it = it->next;
    }
    printf("\n");
}

void freeList(LinkedList *list) {
    Node *it = list->head;
    while (it != NULL) {
        Node *temp = it;
        it = it->next;
        free(temp);
    }
    list->head = list->tail = NULL;
    list->size = 0;
}

int main() {
    LinkedList list = newList();
    for (int i = 1; i <= 5; i++) {
        addTail(&list, i);
    }
    displayList(list);
    freeList(&list);
}