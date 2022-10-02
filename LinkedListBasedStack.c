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

int main() {
    Stack stack = newStack();
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    while (!isEmpty(&stack)) {
        Node *node = pop(&stack);
        printf("%d ", node->data);
    }
    return 0;
}
