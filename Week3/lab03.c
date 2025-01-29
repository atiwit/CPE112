#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void traverse(node *start) {
    node *ptr = start; // Set to first node
    if (start == NULL)
    {
        printf("none");
    }
    
    while (ptr != NULL) { // Null = last node
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertBegin(node **start, int val) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}

void insertEnd(node **start, int val) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL; // Last node

    if (*start == NULL) {
        *start = newNode;
    } else {
        // Traverse to the last node
        node *ptr = *start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}


void insertBefore(node **start, int num, int val) {
    if (*start == NULL) return; 

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    node *ptr = *start;
    node *prePtr = NULL;

    if (ptr->data == num) { 
        newNode->next = *start;
        *start = newNode;
        return;
    }

    while (ptr != NULL && ptr->data != num) {
        prePtr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) { 
        free(newNode);
        return;
    }

    prePtr->next = newNode;
    newNode->next = ptr;
}

int main() {
    char mode[5];
    int val;
    node *start = NULL; 

    while (1) {
        scanf("%s", mode);

        if (strcmp(mode, "END") == 0) {
            break;
        } else if (strcmp(mode, "INSH") == 0) {
            scanf("%d", &val);
            insertBegin(&start, val);
        } else if (strcmp(mode, "INSE") == 0) {
            scanf("%d", &val);
            insertEnd(&start, val);
        } else if (strcmp(mode, "INSL") == 0) {
            int a,b;
            scanf("%d %d",&a,&b);
            insertBefore(&start,a,b);

        }
    }

traverse(start);
    return 0;
}