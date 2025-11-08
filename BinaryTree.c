#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct TreeNode{
    int treedata;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;


TreeNode* createTreeNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->treedata = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


//stack
typedef struct stackNode{
    TreeNode* stackadata;
    struct stackNode* next;
}stackNode;

stackNode* top = NULL;

stackNode* createStackNode(TreeNode* data){
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    newNode->stackadata = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(){
    return top == NULL;
}

void push(TreeNode* data){
    stackNode* newNode = createStackNode(data);
    if(!newNode){
        printf("Memory Allocation failed.\n");
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
    TreeNode* returnvalue = top->stackadata;
    top = top->next;
    free(t);
    return returnvalue;
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
    free(t);
    return returnvalue;
}

TreeNode* createBinaryTree(TreeNode* root){
    int val,op;
    printf("Enter data: ");
    scanf("%d",&val);
    root = createTreeNode(val);
    printf("Enter 1 to create left of %d, else enter -1: ",root->treedata);
    scanf("%d",&op);
    if(op){
        root->left = createBinaryTree(root->left);
    }

    printf("Enter 1 to create right of %d, else enter -1: ",root->treedata);
    scanf("%d",&op);
    if(op){
        root->right = createBinaryTree(root->right);
    }

    return root;
}

void recursivePreorder(TreeNode* root){
    if(root==NULL)return;
    printf("%d ",root->treedata);
    recursivePreorder(root->left);
    recursivePreorder(root->right);
}

void recursiveInorder(TreeNode* root){
    if(root==NULL)return;
    recursiveInorder(root->left);
    printf("%d ",root->treedata);
    recursiveInorder(root->right);
}

void recursivePostorder(TreeNode* root){
    if(root==NULL)return;
    recursivePostorder(root->left);
    recursivePostorder(root->right);
    printf("%d ",root->treedata);
}

void iterativePreorder(TreeNode* root){
    if(root==NULL)return;
    push(root);
    while(!isEmpty()){
        TreeNode* node = pop();
        printf("%d ",node->treedata);
        if(node->right!=NULL) push(node->right);
        if(node->left!=NULL) push(node->left);
    }
}

void iterativeInorder(TreeNode* root){
    if(root==NULL)return;
    TreeNode* node = root;
    while(!isEmpty()||node!=NULL){
        while(node!=NULL){
            push(node);
            node = node->left;
        }
        node = pop();
        printf("%d ",node->treedata);
        node = node->right;
    }
}

void iterativePostorder(TreeNode* root){
    if(root==NULL)return;
    int arr [100];
    int k = 0;
    push(root);
    while(!isEmpty()){
        TreeNode* node = pop();
        arr[k++] = node->treedata;
        if(node->left!=NULL) push(node->left);
        if(node->right!=NULL) push(node->right);
    }
    for(int i=k-1; i>=0; i--){
        printf("%d ",arr[i]);
    }
}

void levelOrder(TreeNode* root){
    if(root==NULL)return;
    enqueue(root);
    while(!isQueueEmpty()){
        TreeNode* node = dequeue();
        printf("%d ",node->treedata);
        if(node->left!=NULL)enqueue(node->left);
        if(node->right!=NULL)enqueue(node->right);
    }
}

int height(TreeNode* root){
    if(root==NULL)return 0;
    return 1+MAX(height(root->left),height(root->right));
}

int leafCount(TreeNode* root){
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL) return 1;
    return leafCount(root->left)+leafCount(root->right);
}

int printParent(TreeNode* root, int data){
    if(root==NULL)return 0;
    if(((root->left!=NULL&&root->left->treedata==data)||(root->right!=NULL&&root->right->treedata==data))){
        printf("%d is Parent of %d\n",root->treedata,data);
        return 1;
    }
    return printParent(root->left,data)||printParent(root->right,data);
}

int printAncestors(TreeNode* root, int target){
    if(root==NULL)return 0;
    if(root->treedata==target)return 1;
    if(printAncestors(root->left,target)||printAncestors(root->right,target)){
        printf("%d ",root->treedata);
        return 1;
    }
    return 0;
}



int main(){
    TreeNode* root = createBinaryTree(NULL);
    printf("Recursive preorder: ");
    recursivePreorder(root);
    printf("\n");
    printf("Recursive inorder: ");
    recursiveInorder(root);
    printf("\n");
    printf("Recursive postorder: ");
    recursivePostorder(root);
    printf("\n");
    printf("Iterative preorder: ");
    iterativePreorder(root);
    printf("\n");
    printf("Iterative inorder: ");
    iterativeInorder(root);
    printf("\n");
    printf("Iterative postorder: ");
    iterativePostorder(root);
    printf("\n");
    printf("Level order Traversal: ");
    levelOrder(root);
    printf("\n");
    printf("Height of Tree: ");
    printf("%d\n",height(root));
    printf("Number of leaf Nodes: ");
    printf("%d\n",leafCount(root));
    printParent(root,6);
    printf("Print ancestors: ");
    printAncestors(root,7);
    printf("\n");
    return 0;
}