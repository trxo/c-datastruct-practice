#include <stdio.h>
#include "bst.h"
#include <malloc.h>


Tree* NewTree()
{
    Tree *t = (Tree*)malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}

TreeNode* NewNode(ElementType data)
{
    TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(Tree *t, ElementType data)
{
    if (t->root == NULL){
        t->root = NewNode(data);
        return;
    }
    TreeNode *parentPtr;
    TreeNode *currentPtr = t->root;
    while (1) {
        parentPtr = currentPtr;
        if (data < currentPtr->data){
            currentPtr = currentPtr->left;
            if(currentPtr == NULL) {
                parentPtr->left = NewNode(data);
                break;
            }
        } else {
            currentPtr = currentPtr->right;
            if(currentPtr == NULL) {
                parentPtr->right = NewNode(data);
                break;
            }
        }
    }
}

void inOrder(TreeNode *n){
    if (n != NULL){
        inOrder(n->left);
        printf("node data is: %d\n",n->data);
        inOrder(n->right);
    }
}

void preOrder(TreeNode *n){
    if (n!=NULL){
        printf("node data is: %d\n",n->data);
        preOrder(n->left);
        preOrder(n->right);
    }
}

void postOrder(TreeNode *n){
    if (n!=NULL){
        postOrder(n->left);
        postOrder(n->right);
        printf("node data is: %d\n",n->data);
    }
}

ElementType getMin(Tree *t){
    TreeNode *currentPtr = t->root;
    while (currentPtr->left != NULL){
        currentPtr = currentPtr->left;
    }
    return currentPtr->data;
}

ElementType getMax(Tree *t){
    TreeNode *currentPtr = t->root;
    while (currentPtr->right != NULL) {
        currentPtr = currentPtr->right;
    }
    return currentPtr->data;
}
TreeNode* find(Tree *t,ElementType data)
{
    TreeNode *currentPtr = t->root;
    while (currentPtr != NULL) {
        if (currentPtr->data == data){
            return currentPtr;
        } else if (data < currentPtr->data){
            currentPtr = currentPtr->left;
        } else {
            currentPtr = currentPtr->right;
        }
    }
}


int main() {
    Tree *t = NewTree();
    insert(t,1);
    insert(t,2);
    insert(t,3);
    inOrder(t->root);
    return 0;
}