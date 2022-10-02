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

Queue newQueue() {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    queue.size = 0;
    return queue;
}

int isEmpty(Queue *queue) {
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

int main() {
    Queue queue = newQueue();
    for (int i = 0; i < 10; i++) {
        enqueue(&queue, i);
    }
    while (!isEmpty(&queue)) {
        Node *node = dequeue(&queue);
        printf("%d ", node->data);
        free(node);
    }
}