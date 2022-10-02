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

typedef struct Stack {
    Node *head;
    int size;
} Stack;

Stack newStack() {
    Stack stack;
    stack.head = NULL;
    stack.size = 0;
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->head == NULL;
}

void push(Stack *stack, int data) {
    if (isEmpty(stack)) {
        stack->head = newNode(data);
    } else {
        Node *node = newNode(data);
        node->next = stack->head;
        stack->head = node;
    }
    stack->size++;
}

Node *pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return NULL;
    }
    Node *node = stack->head;
    stack->head = stack->head->next;
    stack->size--;
    return node;
}

Node *peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return NULL;
    }
    return stack->head;
}

void chooseClothes() {
    char clothesList[5][10] = {"blue", "yellow", "red", "deep blue", "green"};
    int dryLeftDay[5] = {[0 ... 4] = -1};

    Stack clothesStack = newStack();
    for (int i = 0; i < 5; i++) {
        push(&clothesStack, i);
    }

    int dryDay = 2;

    for (int day = 1; day <= 10; day++) {
        for(int i = 0; i < 5; i++) {
            dryLeftDay[i]--;
        }
        int clothes = pop(&clothesStack)->data;
        printf("Day %d is clothes %s. \n", day, clothesList[clothes]);
        dryLeftDay[clothes] = dryDay;
        for (int i = 0; i < 5; i++) {
            if (dryLeftDay[i] == 0) {
                push(&clothesStack, i);
            }
        }
    }
}

int main() {
    chooseClothes();
    return 0;
}
