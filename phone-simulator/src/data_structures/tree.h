#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data);
void insert(TreeNode** root, int data);
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);
void freeTree(TreeNode* root);

#endif // TREE_H