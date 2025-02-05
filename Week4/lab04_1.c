#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node **top, int data) {
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

void pop(Node **top) {
    if (*top) {
        Node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void printStack(Node *stack) {
    if (!stack) {
        printf("none");
    } else {
        while (stack) {
            printf("%d ", stack->data);
            stack = stack->next;
        }
    }
}

int main() {
    char choice[10];
    Node *stack = NULL;
    int val;

    while (1) {
        scanf("%s", choice);

        if (strcmp(choice, "PUSH") == 0) {
            scanf("%d", &val);
            push(&stack, val);
        } else if (strcmp(choice, "PEEK") == 0) {
            if (stack) {
               printf("%d\n", stack->data);
            } else {
               printf("none\n");
            }
        } else if (strcmp(choice, "POP") == 0) {
            pop(&stack);
        } else if (strcmp(choice, "END") == 0) {
            printStack(stack);
            break;
        }
    }
}
