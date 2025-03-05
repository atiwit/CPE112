#include <stdio.h>
#include <stdlib.h>

#include "treeavl.h"

TREENODE_T *newNodeCreate (int val){
    TREENODE_T* new_node;
    new_node = (TREENODE_T *)calloc(1,sizeof(TREENODE_T)); //n = 1
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 0;
    new_node->balance = 0;
    return new_node;
}

int setChildNode (TREENODE_T* parent, TREENODE_T* child, char direction) {
    int success = 1;
    if(direction == 'L') {
        parent->left = child;
    }else if (direction == 'R'){
        parent->right = child;
    }
    else success = 0;
    return success;
}

void postOrder(TREENODE_T* node){

    if(node->left != NULL) {
        postOrder(node->left);
    }
    if(node->right != NULL){
        postOrder(node->right);
    }
    printf("access %d\n",node->data);
}

int countNodes (TREENODE_T *n){
    int nodes = 0;
    if (n == NULL) nodes = 0;
    else {
        nodes = countNodes(n->left) + countNodes(n->right) +1;
    }
    return nodes;
}

void addRoot(TREENODE_T* root, int val) {
    root = newNodeCreate(val);
}

void addLeftChild(TREENODE_T* parent, int val) {
    if (parent != NULL) {
        parent->left = newNodeCreate(val);
    }
}

void addRightChild(TREENODE_T* parent, int val) {
    if (parent != NULL) {
        parent->right = newNodeCreate(val);
    }
}

void fillHeight (TREENODE_T *node) { 
    int height = 0; 
    if (node->left != NULL)  fillHeight(node->left); 
    if (node->right != NULL)   fillHeight(node->right); 

    if (node->left == NULL && node->right == NULL)   height = 0;   //Case1 
    else if (node->left == NULL)   height = node->right->height +1;  //Case2 
    else if (node->right == NULL)   height = node->left->height +1;  //Case3 
    else if (node->right->height > node->left->height)   height = node->right->height +1; //Case4 
    else   height = node->left->height +1;  //Case5 
    node->height = height; 
}

void fillBalanceFactor (TREENODE_T *node) 
{ 
    int leftHeight = 0, rightHeight = 0; 

    if (node == NULL) return;  // Base case

    // Recursively calculate balance factor for left and right subtrees
    if (node->left != NULL)  
        fillBalanceFactor(node->left); 
    if (node->right != NULL)   
        fillBalanceFactor(node->right); 

    // Get the height of the left sub-tree
    if (node->left == NULL)   
        leftHeight = 0; 
    else 
        leftHeight = node->left->height;

    // Get the height of the right sub-tree 
    if (node->right == NULL)   
        rightHeight = 0; 
    else 
        rightHeight = node->right->height;

    // Compute balance factor
    node->balance = leftHeight - rightHeight;

    // Update the node's height (assuming height is stored in each node)
    node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


TREENODE_T *rotateRight (TREENODE_T *node) { 
    TREENODE_T *temp; 
    temp = node->left; 
    node->left = temp->right; 
    temp->right = node; 
    node = temp; 
    return(node); 
}

TREENODE_T *rotateLeft (TREENODE_T *node) { 
    TREENODE_T *temp; 
    temp = node->right; 
    node->right = temp->left; 
    temp->left = node; 
    node = temp; 
    return(node); 
}


int main (){
    // TREENODE_T *N1 = newNodeCreate(1);
    // TREENODE_T *N2 = newNodeCreate(2);
    // TREENODE_T *N3 = newNodeCreate(4);
    // TREENODE_T *N4 = newNodeCreate(15);
    // TREENODE_T *N5 = newNodeCreate(16);

    // int status;
    // status = setChildNode(N1,N2,'L');
    // status = setChildNode(N1,N3,'R');
    // status = setChildNode(N2,N4,'L');
    // status = setChildNode(N3,N2,'L');

    // //del node
    // free(N3);
    // N1->right = NULL;
    // free(N2);
}
