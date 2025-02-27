//67070501048 Atiwit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *front,*rear;
    
}Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQ(Queue *q, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) { 
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void deQ(Queue *q) {
    if (q->front == NULL) {
        return;
    }
    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) { 
        q->rear = NULL;
    }
    free(temp);
}

void displayQ(Queue *q) {
    Node *temp = q->front;
    if (q->front == NULL)
    {
        printf("none\n");
    }
    else {
    while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
    }
    printf("\n");
    }
    }
    

    
int main() {
    char ans[10];
        int val;
        Queue *Q = createQueue();

    while(1) {

        scanf("%s",ans);
        if (strcmp(ans,"END") == 0) {
            displayQ(Q);
            break;
        }else if (strcmp(ans, "ENQ") == 0) {
            scanf("%d", &val);
            enQ(Q, val);

        }
        else if (strcmp(ans, "DEQ") == 0) {
            deQ(Q);
        }
        else if (strcmp(ans, "FRONT") == 0) {
             if (Q->front != NULL) {
               printf("%d\n", Q->front->data);
            } else {
               printf("none\n");
            }
        }
    }
}