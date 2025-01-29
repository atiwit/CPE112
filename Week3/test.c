#include <stdio.h>

    typedef struct node {
     int data;
     struct node *next;
    }node;

void traverse(node *start) {
     node *ptr = start; //set to first node
            while(ptr != NULL) { //Null = last node
            ptr = ptr->next;
        }
    }
//print datanode
void printData(node *start) {
    int count = 0;
    node *ptr = start;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    printf("Num node = %d.\n",count);
}

//insert begin
void insertBegin(node **start){
    node *newNode;
    int val;

    printf("Enter data: ");
    scanf("%d",&val);

    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}
//insert End
void insertEnd(node **start) {
    node *newNode, *ptr;
    int val;
    printf("Enter data: ");
    scanf("%d",&val);
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;// last node

    ptr = *start;
    while (ptr->next = NULL)
        ptr = ptr->next;
    ptr->next = newNode;    
    
}
void insertAfter(node **start,int num) {
    node *newNode, *ptr, *prePtr;
    int val;

    printf("Enter data: ");
    scanf("%d",&val);
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;// last node
    ptr = *start;
    prePtr = ptr;
    while (prePtr->data != num)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = newNode;
    newNode->next = ptr;
    
}

void insertBefore(node **start,int num) {
    node *newNode, *ptr, *prePtr;
    int val;

    printf("Enter data: ");
    scanf("%d",&val);
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;// last node
    ptr = *start;
    prePtr = ptr;
    while (ptr->data != num)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = newNode;
    newNode->next = ptr;
    
}
int main() {
    
}