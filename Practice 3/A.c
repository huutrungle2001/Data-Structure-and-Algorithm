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

void freeDList(DList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

int main() {
    DList *list = newDList();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        addTail(list, data);
    }

    display(list);
    reverseDisplay(list);

    freeDList(list);
    return 0;
}