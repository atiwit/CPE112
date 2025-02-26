#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

TREENDODE_T *newNodeCreate (int val){
    TREENDODE_T* new_node;
    new_node = (TREENDODE_T *)calloc(1,sizeof(TREENDODE_T)); //n = 1
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int setChildNode (TREENDODE_T* parent, TREENDODE_T* child, char direction) {
    int success = 1;
    if(direction == 'L') {
        parent->left = child;
    }else if (direction == 'R'){
        parent->right = child;
    }
    else success = 0;
    return success;
}

void postOrder(TREENDODE_T* node){

    if(node->left != NULL) {
        postOrder(node->left);
    }
    if(node->right != NULL){
        postOrder(node->right);
    }
    printf("access %d\n",node->data);
}

int countNodes (TREENDODE_T *n){
    int nodes = 0;
    if (n == NULL) nodes = 0;
    else {
        nodes = countNodes(n->left) + countNodes(n->right) +1;
    }
    return nodes;
}

void addRoot (int bt[],int val){
    bt[0] = val;
}

void addLeftChild(int bt[],int idx,int val) {
    bt[2 * idx + 1] = val;
}

void addRightChild(int bt[],int idx, int val){
    bt[2 * idx +2] = val;
}



int main (){
    TREENDODE_T *N1 = newNodeCreate(1);
    TREENDODE_T *N2 = newNodeCreate(2);
    TREENDODE_T *N3 = newNodeCreate(4);
    TREENDODE_T *N4 = newNodeCreate(15);
    TREENDODE_T *N5 = newNodeCreate(16);

    int status;
    status = setChildNode(N1,N2,'L');
    status = setChildNode(N1,N3,'R');
    status = setChildNode(N2,N4,'L');
    status = setChildNode(N3,N2,'L');

    //del node
    free(N3);
    N1->right = NULL;
    free(N2);
}
