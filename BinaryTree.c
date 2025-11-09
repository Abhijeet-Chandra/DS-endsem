#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct TreeNode{
    int treedata;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;


TreeNode* createTreeNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->treedata = data;
    newNode->height = 1;
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

int isSame(TreeNode* root1, TreeNode* root2){
    if(root1==NULL&&root2==NULL) return 1;
    if(root1==NULL||root2==NULL)return 0;
    if(root1->treedata!=root2->treedata)return 0;
    return isSame(root1->left,root2->left)&&isSame(root1->right,root2->right);
}

int isMirror(TreeNode* root1, TreeNode* root2){
    if(root1==NULL&&root2==NULL)return 1;
    if(root1==NULL||root2==NULL)return 0;
    if(root1->treedata!=root2->treedata)return 0;
    return isMirror(root1->left,root2->right)&&isMirror(root1->right,root2->left);
}

TreeNode* createBST(TreeNode* root, int data){

    if(root==NULL){
        TreeNode* newNode = createTreeNode(data);
        return newNode;
    }

    if(data<root->treedata)
        root->left = createBST(root->left,data);
    if(data>root->treedata)
        root->right = createBST(root->right,data);

    return root;
}

int searchBST(TreeNode* root, int target){
    if(root==NULL)return 0;
    if(root->treedata == target) return 1;
    if(target<root->treedata) return searchBST(root->left,target);
    if(target>root->treedata) return searchBST(root->right,target);
    return 0;
}

int findMin(TreeNode* root){
    TreeNode* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->treedata;
}

int findMax(TreeNode* root){
    
    TreeNode* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->treedata;
}

TreeNode* deleteNodeBST(TreeNode* root, int target){
    if(root==NULL)return NULL;
    if(root->treedata==target){
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        if(root->left!=NULL&&root->right==NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        if(root->right!=NULL&&root->left==NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        if(root->left!=NULL&&root->right!=NULL){
            int min = findMin(root->right);
            root->treedata = min;
            root->right = deleteNodeBST(root->right,min);
            return root;
        }
    }
    else if(target<root->treedata){
        root->left = deleteNodeBST(root->left,target);
    }
    else if(target>root->treedata){
        root->right = deleteNodeBST(root->right,target);
    }
    return root;
}

int heightAVL(TreeNode* root){
    if(root==NULL)return 0;
    return root->height;
}

int balance(TreeNode* root){
    if(root==NULL)return 0;
    return heightAVL(root->left)-heightAVL(root->right);
}

TreeNode* rotateLeft(TreeNode* root){
    TreeNode* child = root->right;
    TreeNode* leftChild = child->left;
    child->left = root;
    root->right = leftChild;
    root->height = 1+MAX(heightAVL(root->left),heightAVL(root->right));
    child->height = 1+MAX(heightAVL(child->left),heightAVL(child->right));
    return child;
}

TreeNode* rotateRight(TreeNode* root){
    TreeNode* child = root->left;
    TreeNode* rightChild = child->right;
    child->right = root;
    root->left = rightChild;
    root->height = 1+MAX(heightAVL(root->left),heightAVL(root->right));
    child->height = 1+MAX(heightAVL(child->left),heightAVL(child->right));
    return child;
}

TreeNode* createAVL(TreeNode* root,int data){
    if(root==NULL){
        TreeNode* newNode = createTreeNode(data);
        return newNode;
    }

    if(data<root->treedata) root->left = createAVL(root->left,data);
    else if(data>root->treedata) root->right = createAVL(root->right,data);
    else return root;

    root->height = 1+MAX(heightAVL(root->left),heightAVL(root->right));
    int bal = balance(root);

    //LL case
    if(bal>1&&data<root->left->treedata){
        return rotateRight(root);
    }

    //RR case
    if(bal<-1&&data>root->right->treedata){
        return rotateLeft(root);
    }

    //LR case
    if(bal>1&&data>root->left->treedata){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    //RL case
    if(bal<-1&&data<root->right->treedata){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

Node* head = NULL, *tail = NULL;

void BSTtoDLL(TreeNode* root){
    if(root==NULL)return;
    BSTtoDLL(root->left);
    Node* newNode = createNode(root->treedata);
    if(head==NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }
    BSTtoDLL(root->right);
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
    printf("Create another tree:\n");
    TreeNode* root2 = createBinaryTree(NULL);
    printf("Is Same: %d\n",isSame(root,root2));
    printf("Is mirror: %d\n",isMirror(root,root2));

    printf("BST creation: \n");
    TreeNode* bstroot = NULL;
    int data;
    for(int i = 0; i<8; i++){
        printf("Enter data: ");
        scanf("%d",&data);
        bstroot = createBST(bstroot,data);
    }
    
    printf("Preorder: ");
    recursivePreorder(bstroot);
    printf("\n");
    printf("Inorder: ");
    recursiveInorder(bstroot);
    printf("\n");
    printf("Postorder: ");
    recursivePostorder(bstroot);
    printf("\n");
    printf("Max in BST: %d\n",findMax(bstroot));
    printf("Min in BST: %d\n",findMin(bstroot));
    root = deleteNodeBST(bstroot,6);
    printf("Inorder after deletion: ");
    recursiveInorder(bstroot);
    printf("\n");
    printf("AVL creation: \n");
    TreeNode* avlroot = NULL;
    for(int i = 0; i<8; i++){
        printf("Enter data: ");
        scanf("%d",&data);
        avlroot = createAVL(avlroot,data);
    }

    printf("Preorder: ");
    recursivePreorder(avlroot);
    printf("\n");
    printf("Inorder: ");
    recursiveInorder(avlroot);
    printf("\n");
    printf("Postorder: ");
    recursivePostorder(avlroot);
    printf("\n");   

    printf("BST to DLL: \n");
    
    BSTtoDLL(bstroot);
    Node* temp = head;
    while(temp!=NULL){
        printf("%d<=>",temp->data);
        temp = temp->next;
    }
    return 0;
}