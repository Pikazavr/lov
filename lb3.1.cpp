#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Структура узла приоритетной очереди
struct Node {
    char data[256];
    int priority;  
    struct Node* next;
};

// Структура приоритетной очереди
struct PriorityQueue {
    struct Node* front;
};

// Структура обычной очереди
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Создание новой приоритетной очереди
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->front = NULL;
    return queue;
}

// Создание новой обычной очереди
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Проверка, пуста ли обычная очередь
int isEmptyQueue(struct Queue* queue) {
    return queue->front == NULL;
}

// Проверка, пуста ли приоритетная очередь
int isEmptyPriorityQueue(struct PriorityQueue* queue) {
    return queue->front == NULL;
}

// Добавление элемента в обычную очередь
void enqueueQueue(struct Queue* queue, const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (isEmptyQueue(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Извлечение элемента из обычной очереди
char* dequeueQueue(struct Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Очередь пуста!\n");
        return NULL;
    }

    struct Node* temp = queue->front;
    char* data = (char*)malloc(strlen(temp->data) + 1); 
    strcpy(data, temp->data);

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Вывод содержимого обычной очереди
void printQueue(struct Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Очередь пуста!\n");
        return;
    }

    struct Node* current = queue->front;
    while (current != NULL) {
        printf("\"%s\" ", current->data); 
        current = current->next;
    }
    printf("\n");
}

void enqueuePriorityQueue(struct PriorityQueue* queue, const char* data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->priority = priority;
    newNode->next = NULL;

    if (isEmptyPriorityQueue(queue) || priority > queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    }
    else {
        struct Node* current = queue->front;
        while (current->next != NULL && priority <= current->next->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Извлечение элемента из приоритетной очереди
char* dequeuePriorityQueue(struct PriorityQueue* queue) {
    if (isEmptyPriorityQueue(queue)) {
        printf("Очередь пуста!\n");
        return NULL;
    }

    struct Node* temp = queue->front;
    char* data = (char*)malloc(strlen(temp->data) + 1); 
    strcpy(data, temp->data);

    queue->front = queue->front->next;

    free(temp);
    return data;
}

// Вывод содержимого приоритетной очереди
void printPriorityQueue(struct PriorityQueue* queue) {
    if (isEmptyPriorityQueue(queue)) {
        printf("Очередь пуста!\n");
        return;
    }

    struct Node* current = queue->front;
    while (current != NULL) {
        printf("\"%s\" ", current->data); 
        current = current->next;
    }
    printf("\n");
}

// Функция для получения приоритета (можно изменять для разных задач)
int getPriority(const char* data) {
   return strlen(data);
}

int main() {
    setlocale(LC_ALL, "Rus");
    struct Queue* queue = createQueue();

    enqueueQueue(queue, "task 1");
    enqueueQueue(queue, "task 2 ");
    enqueueQueue(queue, "task 3 ");
    enqueueQueue(queue, "task 4 ");

    printf("Очередь: ");
    printQueue(queue);

    struct PriorityQueue* priorityQueue = createPriorityQueue(); 
    while (!isEmptyQueue(queue)) {
        char* data = dequeueQueue(queue);
        int priority = getPriority(data);
        enqueuePriorityQueue(priorityQueue, data, priority); 
        free(data); // Освобождаем память, выделенную для data
    }

    printf("Приоритетная очередь: ");
    printPriorityQueue(priorityQueue);

    
    free(queue);
    free(priorityQueue);

    return 0;
}
