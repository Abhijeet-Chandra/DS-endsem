#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTreeNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data =data;
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


void preorder(TreeNode* root){
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

TreeNode* createUsingLevelOrder(){
    int data,op;
    printf("Enter root's data: ");
    scanf("%d",&data);
    TreeNode* root = createTreeNode(data);
    enqueue(root);
    while(!isQueueEmpty()){
        TreeNode* node = dequeue();
        printf("Enter 1 to create left of %d, enter 0 to skip: ",node->data);
        scanf("%d",&op);
        if(op==1){
            printf("Enter data: ");
            scanf("%d",&data);
            node->left = createTreeNode(data);
            enqueue(node->left);
        }

        printf("Enter 1 to create right of %d, enter 0 to skip: ",node->data);
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

int main(){
    TreeNode* root = createUsingLevelOrder();
    preorder(root);
}