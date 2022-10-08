#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *newNode(char data) {
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

void push(Stack *stack, char data) {
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

void infixToPostfix(char *infix, char *postfix) {
    Stack stack = newStack();
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(&stack)->data != '(') {
                postfix[j++] = pop(&stack)->data;
            }
            pop(&stack);
        } else if (infix[i] == '+' || infix[i] == '-') {
            while (!isEmpty(&stack) && peek(&stack)->data != '(') {
                postfix[j++] = pop(&stack)->data;
            }
            push(&stack, infix[i]);
        } else if (infix[i] == '*' || infix[i] == '/') {
            while (!isEmpty(&stack) && (peek(&stack)->data == '*' || peek(&stack)->data == '/')) {
                postfix[j++] = pop(&stack)->data;
            }
            push(&stack, infix[i]);
        } else if (infix[i] == '^') {
            while (!isEmpty(&stack) && peek(&stack)->data == '^') {
                postfix[j++] = pop(&stack)->data;
            }
            push(&stack, infix[i]);
        } else if (infix[i] == ' ') {
            i++;
            continue;
        } else {
            postfix[j++] = infix[i];
        }
        i++;
    }
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack)->data;
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) {
    Stack stack = newStack();
    int i = 0;
    while (postfix[i] != '\0') {
        if (postfix[i] == ' ') {
            i++;
            continue;
        } else if (postfix[i] == '+') {
            int a = pop(&stack)->data - '0';
            int b = pop(&stack)->data - '0';
            push(&stack, a + b + '0');
        } else if (postfix[i] == '-') {
            int a = pop(&stack)->data - '0';
            int b = pop(&stack)->data - '0';
            push(&stack, b - a + '0');
        } else if (postfix[i] == '*') {
            int a = pop(&stack)->data - '0';
            int b = pop(&stack)->data - '0';
            push(&stack, a * b + '0');
        } else if (postfix[i] == '/') {
            int a = pop(&stack)->data - '0';
            int b = pop(&stack)->data - '0';
            push(&stack, b / a + '0');
        } else if (postfix[i] == '^') {
            int a = pop(&stack)->data - '0';
            int b = pop(&stack)->data - '0';
            int c = 1;
            for (int i = 0; i < a; i++) {
                c *= b;
            }
            push(&stack, c + '0');
        } else {
            push(&stack, postfix[i]);
        }
        i++;
    }
    return pop(&stack)->data - '0';
}

void testInfixToPostfix() {
    printf("INFIX TO POSFIX TEST\n");
    char infix[100], postfix[100];
    strcpy(infix, "A*B+C*((D-E)+F)/G");
    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    strcpy(infix, "A + (B*C - (D/E^F) * G) * H");
    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Postfix: %s\n", postfix);

    strcpy(infix, "A + (B*C - (D/E^F) * G) * H");
    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Postfix: %s\n", postfix);

    strcpy(infix, "1 + (3*3 - (9/3^2) * 4) * 2");
    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    printf("\n");
}

void testEvaluatePostfix() {
    printf("EVALUATE POSTFIX TEST\n");
    char postfix[100];
    strcpy(postfix, "133*932^/4*-2*+");
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    strcpy(postfix, "2 3 4 + 5 6 - - *");
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    printf("\n");
}

int main() {
    testInfixToPostfix();
    testEvaluatePostfix();
    return 0;
}