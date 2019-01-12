//
// Created by trxo on 2019/1/11.
//

#ifndef BST_BST_H
#define BST_BST_H

typedef int ElementType;

typedef struct TreeNodeStruct {
    ElementType data;
    struct TreeNodeStruct *left;
    struct TreeNodeStruct *right;
} TreeNode;

typedef struct {
    TreeNode *root;
} Tree;

Tree* NewTree();
TreeNode* NewNode(ElementType data);
void insert(Tree *t, ElementType data);
void inOrder(TreeNode *n);
void preOrder(TreeNode *n);
void postOrder(TreeNode *n);


#endif //BST_BST_H
