#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

TREENODE_T *newNodeCreate (int val){
    TREENODE_T* new_node;
    new_node = (TREENODE_T *)calloc(1,sizeof(TREENODE_T)); //n = 1
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
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

TREENODE_T* binarySearch (TREENODE_T* root, int key) 
{ 
    TREENODE_T *p, *node; 
    p = root; node = NULL; 
    do { 
    if (p->data == key) node = p;      /*Search found*/ 
    else if (p->data > key) p = p->left; 
    else p = p->right; 
    } while ((p != NULL) && (node == NULL)); 
    return (node);  
}
//ลบแค่ใบ
void deleteTerminalRightNode (TREENODE_T* previous) 
{ 
    TREENODE_T *p; 
    p = previous->right; 
    previous->right = NULL; 
    free(p); 
}
//
void deleteNonTerminalWithOnlyLeftNode (TREENODE_T* previous) { 
    TREENODE_T *p; 
    p = previous->left; 
    previous->left = p->left; 
    free(p); 
}
void deleteNonTerminalRightNode (TREENODE_T* previous) { 
    TREENODE_T *p, *q; 
    p = previous->right; 
    previous->right = q = p->left; 
    while (q->right != NULL) 
    q = q->right; 
    q->right = p->right; 
    free(p); 
}


TREENODE_T* insertNodetoBinaryTree (TREENODE_T* root, TREENODE_T* newNode){
    TREENODE_T *p, *previous;
    previous = NULL;
    p = root;
    //case1
    if(root == NULL) root = newNode; root->left = root->right = NULL;

    //case2
    while (p != NULL)
    {
        previous = p;
        if (newNode->data < p->data) {
            if (p->left == NULL) {
                p->left = newNode;
                return root;
            }
            p = p->left;
        } else {
            if (p->right == NULL) {
                p->right = newNode;
                return root;
            }
            p = p->right;
        }
    }
    return root;
    
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
