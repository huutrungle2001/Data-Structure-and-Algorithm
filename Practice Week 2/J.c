#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int ID;
    int score;
    char name[1000];
    char address[1000];
} Data;

void inputData(Data *data) {
    scanf("%d", &data->ID);
    scanf("%d", &data->score);
    scanf("%s", data->name);
    scanf("%s", data->address);
}

void displayData(Data data) {
    printf("%d %d %s %s\n", data.ID, data.score, data.name, data.address);
}

typedef struct Node {
    Data data;
    struct Node *next;
} Node;

Node *newNode(Data data) {
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

void addHead(LinkedList *list, Data data) {
    Node *node = newNode(data);
    if (list->head == NULL) {
        list->head = list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

void addTail(LinkedList *list, Data data) {
    Node *node = newNode(data);
    if (list->head == NULL) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void addAt(LinkedList *list, Data data, int position) {
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

void addIncreaseID(LinkedList *list, Data data) {
    if (list->head == NULL) {
        addHead(list, data);
        return;
    }

    Node *node = newNode(data);
    Node *it = list->head;
    while (it->next != NULL && it->next->data.ID <= data.ID) {
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

void displayList(const LinkedList *list) {
    if (list->head == NULL) {
        return;
    }

    Node *it = list->head;
    while (it != list->tail->next) {
        displayData(it->data);
        it = it->next;
    }
}

Data getKthElement(LinkedList list, int k) {
    if (k < 0 || k >= list.size) {
        printf("Error: Index out of bounds\n");
        return (Data){0, 0};
    }

    Node *it = list.head;
    while (k-- > 0) {
        it = it->next;
    }
    return it->data;
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

LinkedList getValidList(const LinkedList *list, int minScore, char *address) {
    LinkedList answer = newList();
    Node *it = list->head;
    while (it != list->tail->next) {
        if (it->data.score >= minScore && strcmp(it->data.address, address) == 0) {
            addTail(&answer, it->data);
        }
        it = it->next;
    }
    return answer;
}

int main() {
    freopen("Test_10.txt", "r", stdin);
    freopen("bai4.out", "w", stdout);
    LinkedList list = newList();
    int n, entranceScore;
    char address[1000];
    scanf("%d %d", &n, &entranceScore);
    scanf("%s", address);

    while (n-- > 0) {
        Data data;
        inputData(&data);
        addTail(&list, data);
    }

    // displayList(&list);

    LinkedList validList = getValidList(&list, entranceScore, address);
    printf("Tinh: %s\n", address);
    printf("Tong so thi sinh trung tuyen: %d\n", validList.size);
    displayList(&validList);

    return 0;
}