#include <stdio.h>
#include <stdlib.h>

typedef struct node {
     int data;
     struct node *next;
    }node;

void push(int stack[], int val) {
    if(top == MAX-1) {
        printf("Overflow\n");
        return;
    }
    top++;
    stack[top] = val;
}

int pop(int stack[]){
    int val;
    if (top ==-1)
    { printf("Underlow\n"); return-1;}
    else {
        val = stack[top]; 
        top--; 
        return val;
    }
}

int peek(int stack[]){
    if(top == -1){
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}


//linked list
void pushL(node **top, int val) {
    node *newNode;

    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    if(*top == NULL) {
        newNode->next = NULL;
        *top = newNode;
    } else {
        newNode->next = *top;
        *top = newNode;
    }
}

void popL(node **top) {
    node *ptr;
    if(*top == NULL){
        printf("Underflow\n");
        return;
    }
    ptr = *top;
    *top = (*top)->next;
    free(ptr);
}

void insertQ (ont queue[], int num) {
    if(rear == MAX -1 ){
        printf("Overflow\n");
        return;
    }
    if(front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = num;
}

int deleteQ (int queue[]){
    int val;
    if(front == -1 || front > rear){ // front rear เอามาจากตัวสุดท้ายที่ออกจาก queue
        printf("UNDERFLOW\n");
        return -1;
    } else {
        val = queue[front];
        front++;
    }
}