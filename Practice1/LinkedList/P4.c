#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void insertNode(node **start, int val) {
     node *newNode,*ptr;
     newNode = (node *)malloc(sizeof(node));

    
     if(*start == NULL){
        newNode = *start;
        return;
     }

    newNode->data = val;
    newNode->next = NULL;
     ptr = *start;
     while (ptr->next != NULL)
     {
        ptr = ptr->next;
     }
     ptr->next = newNode; 
     
}

void printNode(node *start){
    node *ptr = start;
    while (start != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int findMax (node *start){
    node *ptr = start;
    int max = -99999;
    
    while (ptr->next != NULL && start != NULL)
    {
        if(ptr->data > max) {
            ptr->data = max;
            ptr = ptr->next;
        } 
    }
    return max;

}

int findMin (node *start){
    node *ptr = start;
    int min = 99999;
    
    while (ptr->next != NULL && start != NULL)
    {
        if(ptr->data < min) {
            ptr->data = min;
            ptr = ptr->next;
        } 
    }
    return min;
}

int main(){

    node *start = NULL;

    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    
}