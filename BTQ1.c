// Binary Tree where each node stores a name.

// Creation of tree

// Postorder traversal

// Find height of the tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct TreeNode{
    char name[20];
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;


TreeNode* createTreeNode(char name []){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->name,name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* buildTree(TreeNode* root){
    int op;
    char name[20];
    printf("Enter name: ");
    scanf("%s",name);
    root = createTreeNode(name);
    printf("Enter 1 to create left of %s, else enter -1: ",root->name);
    scanf("%d",&op);
    if(op==1){
        root->left = buildTree(root->left);
    }
    printf("Enter 1 to create right of %s, else enter -1: ",root->name);
    scanf("%d",&op);
    if(op==1){
        root->right = buildTree(root->right);
    }
    return root;    
}

void postorder(TreeNode* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%s ",root->name);
}

int height(TreeNode* root){
    if(root==NULL)return 0;
    return 1+MAX(height(root->left),height(root->right));
}

int main(){
    TreeNode* root = buildTree(NULL);
    postorder(root);
    printf("\n");
    printf("Height of tree: %d\n",height(root));
    return 0;
}