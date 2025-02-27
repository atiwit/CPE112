#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

// void insertFirst(node **start,int val){
//     node *newNode = (node*)malloc(sizeof(node));
//     newNode->data = val;
//     newNode->next = *start;
//     *start = newNode;
// }
void insert(node **start,int val) {
    node *ptr;
    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = val;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
        return;
    }
     ptr = *start;
     while (ptr->next != NULL)
     {
          ptr = ptr->next;
     }
     ptr->next = newNode;
}

void printNode(node *start){
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}
int main (){
    node *start = NULL;
    int n1,n2;

        scanf("%d",&n1);
        int a[n1];
        for (int i = 0; i < n1; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d",&n2);
        int b[n2];
        for (int i = 0; i < n2; i++) {
            scanf("%d", &b[i]);
        }
        
        //first
        for (int i = 0; i < n1; i++) {
            insert(&start,a[i]);
        }
        //end
        for (int i = 0; i < n2; i++) {
            insert(&start,b[i]);
        }
        printNode(start);

        //free list
        while (start != NULL)
        {
            node *temp = start;
            start = start->next;
            free(temp);
        }
        return 0;
}