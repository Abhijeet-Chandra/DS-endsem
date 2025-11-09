// Binary Tree Operations:

// Iteratively create a binary tree.

// Display the binary tree in tree form.

// Perform iterative preorder traversal.


// Display all non-leaf nodes.

#include<stdio.h>
#include<stdlib.h>


typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTreeNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//queue
typedef struct queueNode{
    TreeNode* queueData;
    struct queueNode* next;
}queueNode;

queueNode* front = NULL;
queueNode* rear = NULL;

int isQueueEmpty(){
    return front == NULL;
}

queueNode* createQueueNode(TreeNode* data){
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->queueData = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(TreeNode* data){
    queueNode* newNode = createQueueNode(data);
    if(!newNode){
        printf("Memory Allocation failed.\n");
        return;
    }
    if(isQueueEmpty()){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

TreeNode* dequeue(){
    if(isQueueEmpty()){
        printf("Queue is empty.\n");
        return NULL;
    }
    queueNode* t = front;
    TreeNode* returnvalue = front->queueData;
    front = front->next;
    if(front == NULL) rear = NULL;
    free(t);
    return returnvalue;
}

TreeNode* iterativeBT(){
    int data,op;
    printf("Enter root's data: ");
    scanf("%d",&data);
    TreeNode* root = createTreeNode(data);
    enqueue(root);
    while(!isQueueEmpty()){
        TreeNode* node = dequeue();

        printf("Enter 1 to create left of %d, 0 to skip: ",node->data);
        scanf("%d",&op);
        if(op==1){
            printf("Enter data: ");
            scanf("%d",&data);
            node->left = createTreeNode(data);
            enqueue(node->left);
        }
        
        printf("Enter 1 to create right of %d, 0 to skip: ",node->data);
        scanf("%d",&op);
        if(op==1){
            printf("Enter data: ");
            scanf("%d",&data);
            node->right = createTreeNode(data);
            enqueue(node->right);
        }
    }
    return root;
}

//stack
typedef struct stackNode{
    TreeNode* data;
    struct stackNode* next;
}stackNode;

stackNode* top = NULL;

int isEmpty(){
    return top==NULL;
}

stackNode* createStackNode(TreeNode* data){
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(TreeNode* data){
    stackNode* newNode = createStackNode(data);
    if(!newNode){
        printf("Memory allocation failed.\n");
        return;
    }
    if(isEmpty()){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

TreeNode* pop(){
    if(isEmpty()){
        printf("Stack underflow.\n");
        return NULL;
    }
    stackNode* t = top;
    TreeNode* returnvalue = top->data;
    top = top->next;
    free(t);
    return returnvalue;
}

void iterativePreorder(TreeNode* root){
    if(root==NULL)return;

    push(root);
    
    while(!isEmpty()){
        TreeNode* node = pop();
        printf("%d ",node->data);
        if(node->right!=NULL)push(node->right);
        if(node->left!=NULL)push(node->left);
    }
    printf("\n");
}

void displayNonLeaf(TreeNode*root){
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL)return;
    printf("%d ",root->data);
    displayNonLeaf(root->left);
    displayNonLeaf(root->right);
}

int main(){
    TreeNode* root = iterativeBT();
    iterativePreorder(root);
    displayNonLeaf(root);
    return 0;
}