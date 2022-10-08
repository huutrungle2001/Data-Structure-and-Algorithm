#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CTDL Node để lưu trữ 1 toán hạng hoặc toán tử
typedef struct Node {
    char data;
    struct Node *next;
} Node;

// Tạo mới 1 node
Node *newNode(char data) {
    // Cấp phát bộ nhớ cho con trỏ node,
    // Vì ban đầu con trỏ chưa trỏ đến ô nhớ nào để mà lưu trữ dữ liệu cả
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// CTDL Stack để lưu trữ các toán hạng và toán tử
typedef struct Stack {
    Node *head;
    int size;
} Stack;

// Tạo mới 1 stack
Stack newStack() {
    Stack stack;
    stack.head = NULL;
    stack.size = 0;
    return stack;
}

// Kiểm tra stack có rỗng không
int isEmpty(Stack *stack) {
    return stack->head == NULL;
}

// Thêm 1 node vào đỉnh stack
void push(Stack *stack, char data) {
    // Nếu stack rỗng thì node mới là head
    if (isEmpty(stack)) {
        stack->head = newNode(data);
    } else {
        // Nếu stack không rỗng thì node mới sẽ trỏ đến head cũ
        Node *node = newNode(data);
        node->next = stack->head;
        stack->head = node;
    }
    stack->size++;
}

// Lấy ra 1 node ở đỉnh stack
Node *pop(Stack *stack) {
    // Nếu stack rỗng thì trả về NULL
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return NULL;
    }
    // Nếu stack không rỗng thì lấy node ở đỉnh stack
    Node *node = stack->head;
    // Cập nhật lại head là node tiếp theo
    stack->head = stack->head->next;
    stack->size--;
    return node;
}

// Lấy ra 1 node ở đỉnh stack nhưng không xóa nó
Node *peek(Stack *stack) {
    // Nếu stack rỗng thì trả về NULL
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return NULL;
    }
    // Nếu stack không rỗng thì lấy node ở đỉnh stack
    return stack->head;
}

// Chuyển biểu thức trung tố sang hậu tố
void infixToPostfix(char *infix, char *postfix) {
    // Khởi tạo 1 stack rỗng
    Stack stack = newStack();
    int i = 0, j = 0;
    // Duyệt qua từng ký tự trong biểu thức trung tố
    while (infix[i] != '\0') {
        // Nếu là ngoặc mở thì thêm vào stack
        if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // Nếu là ngoặc đóng thì lấy ra các toán tử trong stack cho đến khi gặp ngoặc mở
        else if (infix[i] == ')') {
            while (peek(&stack)->data != '(') {
                postfix[j++] = pop(&stack)->data;
            }
            pop(&stack);
        }
        // Nếu là toán tử thì lấy ra các toán tử trong stack có độ ưu tiên cao hơn hoặc bằng
        else if (infix[i] == '+' || infix[i] == '-') {
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
        }
        // Nếu là dấu cách thì bỏ qua
        else if (infix[i] == ' ') {
            i++;
            continue;
        }
        // Nếu là toán hạng thì thêm vào biểu thức hậu tố
        else {
            postfix[j++] = infix[i];
        }
        i++;
    }

    // Lấy ra các toán tử còn lại trong stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack)->data;
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) {
    // Khởi tạo 1 stack rỗng
    Stack stack = newStack();
    int i = 0;
    // Duyệt qua từng ký tự trong biểu thức hậu tố
    while (postfix[i] != '\0') {
        // Nếu là dấu cách thì bỏ qua
        if (postfix[i] == ' ') {
            i++;
            continue;
        }
        // Nếu là toán tử thì lấy ra 2 toán hạng trong stack, thực hiện phép tính và thêm kết quả vào stack
        else if (postfix[i] == '+') {
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
        }
        // Nếu là toán hạng thì thêm vào stack
        else {
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