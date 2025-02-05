#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void Push(Node **top,int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
         return;
    }else {
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;

    }
}
int pop(Node **top) {
    if (*top == NULL) {
        return -1;
    } 
    Node *temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

void displayStack(Node *stack) {
    if(stack == NULL) {
        printf("none");
    }else {
        while(stack) {
            printf("%d ", stack->data);
            stack = stack->next;
        }
        printf("\n");
    }
}
int main() {
    char ans[10];
        int val;
        Node *stack = NULL;
    while(1) {

        scanf("%s",ans);
        if (strcmp(ans,"END") == 0) {
            displayStack(stack);
            break;
        }else if (strcmp(ans, "PUSH") == 0) {
            scanf("%d", &val);
            Push(&stack,val);
        }
        else if (strcmp(ans, "POP") == 0) {
            pop(&stack);
        }
        else if (strcmp(ans, "PEEK") == 0) {
             if (stack) {
               printf("%d\n", stack->data);
            } else {
               printf("none\n");
            }
        }
    }
}