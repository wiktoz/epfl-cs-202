#include <stdlib.h>
#include <stdio.h>

struct Node {
    char *value;
    struct Node* prev;
    struct Node* next;
};

struct DynamicArray {
    struct Node* head;
    struct Node* tail;
    size_t size;
};

char *get(struct DynamicArray *arr, int position) {
    struct Node *currentNode;
    currentNode = arr->head;

    int i;
    for(i = 0; i < position; i++){
        currentNode = currentNode->next;
    }

    return currentNode->value;
}

void change(struct DynamicArray *arr, char *value, int position) {
    struct Node *currentNode;
    currentNode = arr->head;

    int i;
    for(i = 0; i < position; i++){
        currentNode = currentNode->next;
    }

    currentNode->value = value;
}

void insert(struct DynamicArray *arr, char *value, int position) {
    struct Node *currentNode;
    currentNode = arr->head;

    int i;
    for(i = 0; i < position; i++){
        currentNode = currentNode->next;
    }

    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;

    currentNode->prev->next = newNode;
    currentNode->prev = newNode;

    arr->size += 1;
}

void append(struct DynamicArray *arr, char *value) {
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->prev = arr->tail;
    newNode->next = NULL;

    if(arr->size == 0){
        arr->head = newNode;
        arr->tail = newNode;
    }
    else {
        arr->tail->next = newNode;
        arr->tail = newNode;
    }

    arr->size += 1;
}

void print(struct DynamicArray *arr){
    struct Node *currentNode;
    currentNode = arr->head;

    int i;
    for(i = 0; i < arr->size; i++){
        printf("%s", currentNode->value);
        printf("  ");
        currentNode = currentNode->next;
    }

    printf("\n");
}

void destroy(struct DynamicArray *arr) {
    struct Node *nextNode;
    nextNode = arr->head;

    int i;
    for(i = 0; i < arr->size; i++){
        nextNode = nextNode->next;
        free(nextNode->prev);
    }

    free(nextNode);
}

size_t size(struct DynamicArray *arr) {
    return arr->size;
}


int main() {
    struct DynamicArray *arr = NULL;
    arr = malloc(sizeof(struct DynamicArray));
    arr->head = NULL;
    arr->tail = NULL;
    arr->size = 0;

    append(arr, "30");
    print(arr);

    append(arr, "40");
    print(arr);

    insert(arr, "50", 1);
    print(arr);

    destroy(arr);
    free(arr);

    return 0;
}