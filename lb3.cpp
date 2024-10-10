#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[256];
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

struct PriorityQueue* createQueue() {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->front = NULL;
    return queue;
}

bool isEmpty(const struct PriorityQueue* queue) {
    return queue->front == NULL;
}

void enqueue(struct PriorityQueue* queue, const char* data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->priority = priority;
    newNode->next = NULL;

    if (isEmpty(queue) || priority > queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
        return;
    }

    struct Node* current = queue->front;
    while (current->next != NULL && priority <= current->next->priority) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

char* dequeue(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Clear!\n");
        return NULL;
    }

    struct Node* temp = queue->front;
    char* data = (char*)malloc(sizeof(temp->data));
    strcpy(data, temp->data);

    queue->front = queue->front->next;
    free(temp);
    return data;
}

void printQueue(const struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("clear!\n");
        return;
    }

    struct Node* current = queue->front;
    while (current != NULL) {
        printf("Data: %s, priority: %d\n", current->data, current->priority);
        current = current->next;
    }
}

int main() {
    struct PriorityQueue* queue = createQueue();

    enqueue(queue, "task 1", 3);
    enqueue(queue, "task 2", 1);
    enqueue(queue, "task 3", 5);
    enqueue(queue, "task 4", 2);

    printf("ochered:\n");
    printQueue(queue);

    printf("\nElement: %s\n", dequeue(queue));

    printf("\nochered after element:\n");
    printQueue(queue);

    // Освобождаем память
    free(queue);

    return 0;
}