﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Структура узла стека
struct Node {
    char data[256];       
    struct Node* next;    
};

// Структура стека
struct Stack {
    struct Node* top;  
};

// Функция для создания нового стека
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;  
    return stack;
}

// Проверка, пуст ли стек
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Операция добавления элемента в стек (push)
void push(struct Stack* stack, const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = stack->top;  
    stack->top = newNode;        
}

// Операция извлечения элемента из стека (pop)
char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст!\n");
        return NULL;
    }

    struct Node* temp = stack->top;
    char* data = (char*)malloc(strlen(temp->data) + 1);  
    strcpy(data, temp->data);

    stack->top = stack->top->next;  
    free(temp);                     

    return data;
}

// Операция просмотра вершины стека (peek)
char* peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст!\n");
        return NULL;
    }

    return stack->top->data;
}

// Функция для печати содержимого стека
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст!\n");
        return;
    }

    struct Node* current = stack->top;
    printf("Содержимое стека: ");
    while (current != NULL) {
        printf("\"%s\" ", current->data);  
        current = current->next;
    }
    printf("\n");
}

// Освобождение памяти для стека
void freeStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        char* data = pop(stack);  
        free(data);               
    }
    free(stack);  
}

int main() {
    setlocale(LC_ALL, "Rus");
    struct Stack* stack = createStack();

    // Добавляем элементы в стек
    push(stack, "element 1");
    push(stack, "element 2");
    push(stack, "element 3");

    // Печатаем содержимое стека
    printStack(stack);

    // Смотрим элемент на вершине стека
    printf("Вершина стека: \"%s\"\n", peek(stack));

    // Извлекаем элементы из стека
    printf("Извлечен элемент: \"%s\"\n", pop(stack));
    printf("Извлечен элемент: \"%s\"\n", pop(stack));

    // Печатаем содержимое стека после извлечений
    printStack(stack);

    // Освобождаем память
    freeStack(stack);

    return 0;
}
