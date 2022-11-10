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

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *newQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(const Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, int data) {
    Node *node = newNode(data);
    if (isEmpty(queue)) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->size++;
}

Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return NULL;
    }
    Node *node = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    return node;
}

Node *peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return NULL;
    }
    return queue->front;
}

void display(const Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return;
    }
    Node *node = queue->front;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = newQueue();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        enqueue(queue, data);
    }
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue)->data);
    }
}