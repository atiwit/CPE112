#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertBegin(Node **start, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}

void insertEnd(Node **start, int val) {
    Node *newNode, *ptr;
    newNode = (Node*)malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
        return;
    }

    ptr = *start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void printNode(Node *start) {
    Node *ptr = start;
    while (ptr != NULL) { // Null = last node
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int a[5], b[5];
    Node *start = NULL;

    // Input for two arrays
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }

    // Insert elements from array a
    for (int i = 0; i < 5; i++) {
        insertEnd(&start, a[i]);
    }

    // Insert elements from array b
    for (int i = 0; i < 5; i++) {
        insertEnd(&start, b[i]);
    }

    // Print the entire list
    printNode(start);

    // Free the allocated memory
    while (start != NULL) {
        Node *temp = start;
        start = start->next;
        free(temp);
    }

    return 0;
}
