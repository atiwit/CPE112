#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void insertNode(node **start, int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
        newNode->next = newNode;  // Make it circular
        return;
    }

    node *ptr = *start;
    while (ptr->next != *start) {  // Traverse to the last node
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = *start;  // Link last node back to first
}

int josephus(node *start, int k) {
    node *ptr = start, *prev = NULL;

    while (ptr->next != ptr) {  // Run until one node remains
        for (int i = 1; i < k; i++) {  // Move k-1 steps
            prev = ptr;
            ptr = ptr->next;
        }

        // Delete the k-th node
        prev->next = ptr->next;
        free(ptr);
        ptr = prev->next;  // Move to the next person
    }
    int lastPerson = ptr->data;
    free(ptr);
    return lastPerson;
}
void deleteNode(node **start, node *toDelete) {
    if (*start == NULL || toDelete == NULL) return;

    if (*start == toDelete && (*start)->next == *start) {
        free(toDelete);
        *start = NULL;
        return;
    }

    node *ptr = *start;
    while (ptr->next != toDelete) {
        ptr = ptr->next;
    }

    ptr->next = toDelete->next;
    if (*start == toDelete) {
        *start = toDelete->next;
    }
    free(toDelete);
}


int main() {
    node *start = NULL;
    int n, k;
    scanf("%d %d", &n, &k);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Fix scanf issue
    }
    for (int i = 0; i < n; i++) {
        insertNode(&start, arr[i]);
    }

    int lastPerson = josephus(start, k);
    printf("%d\n", lastPerson);

    return 0;
}