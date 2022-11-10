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

Stack *newStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;
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

void display(Stack *stack) {
    Node *temp = stack->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Stack *stack = newStack();
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        push(stack, data);
    }

    Stack *other = newStack();
    while (!isEmpty(stack)) {
        push(other, pop(stack)->data);
    }
    for (int i = 0; i < n - m; i++) {
        printf("%d ", pop(other)->data);
    }
    printf("\n");
    return 0;
}
