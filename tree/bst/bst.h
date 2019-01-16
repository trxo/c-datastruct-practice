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

Tree* NewTree();    // 初始化
TreeNode* NewNode(ElementType data);    // 初始化一个新节点
void insert(Tree *t, ElementType data);  // 插入
void inOrder(TreeNode *n);     // 中序遍历
void preOrder(TreeNode *n);     // 前序遍历
void postOrder(TreeNode *n);    // 后序遍历
TreeNode* find(Tree *t,ElementType data);
ElementType getMin(Tree *t);  // 获取最小值
ElementType getMax(Tree *t); // 获取最大值


#endif //BST_BST_H
