// Details are - Id and name

// Create a BST (by id) with the following operations:

// Insert node recursively

// Delete root node

// Perform postorder traversal iteratively

// Find minimum and maximum id element

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TreeNode{
    char name[20];
    int id;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTreeNode(char name[], int id){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->name,name);
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* createBST(TreeNode* root, char name[], int id){
    if(root==NULL){
        TreeNode* newNode = createTreeNode(name,id);
        return newNode;
    }
    else if(id<root->id){
        root->left = createBST(root->left,name,id);
    }
    else if(id>root->id){
        root->right = createBST(root->right,name,id);
    }
    return root;
}

TreeNode* findMin(TreeNode* root){
    TreeNode* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

TreeNode* findMax(TreeNode* root){
    TreeNode* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

TreeNode* deleteNodeBST(TreeNode* root, int target){
    if(root==NULL)return NULL;
    if(root->id==target){
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }

        if(root->left!=NULL&&root->right==NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        if(root->left==NULL&&root->right!=NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }

        if(root->left!=NULL&&root->right!=NULL){
            TreeNode* min = findMin(root->right);
            int minId = min->id;
            root->id = minId;
            strcpy(root->name,min->name);
            root->right = deleteNodeBST(root->right,minId);
        }
    }

    else if(target<root->id){
        root->left = deleteNodeBST(root->left,target);
    }
    else if(target>root->id){
        root->right = deleteNodeBST(root->right,target);
    }
    return root;
}

typedef struct stackNode{
    TreeNode* data;
    struct stackNode* next;
}stackNode;

stackNode* top = NULL;

int isEmpty(){
    return top == NULL;
}

stackNode* createstackNode(TreeNode* data){
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(TreeNode* data){
    stackNode* newNode = createstackNode(data);
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
        printf("Stack is empty.\n");
        return NULL;
    }

    stackNode* t = top;
    TreeNode* returnvalue = top->data;
    top = top->next;
    free(t);
    return returnvalue;
}

void iterativePostorder(TreeNode* root){
    if(root==NULL)return;
    TreeNode* arr[100];
    int k = 0;
    push(root);
    while(!isEmpty()){
        TreeNode* node = pop();
        arr[k++] = node;
        if(node->left!=NULL)push(node->left);
        if(node->right!=NULL)push(node->right);
    }
    for (int  i = k-1; i >= 0; i--)
    {
        printf("Name: %s,  id: %d\n",arr[i]->name,arr[i]->id);
    }
    printf("\n");
}

int main(){
    TreeNode* root = NULL;
    int n,id;
    char name[20];
    printf("Enter the number of items you want: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter name: ");
        scanf("%s",name);
        printf("Enter id: ");
        scanf("%d",&id);
        root = createBST(root,name,id);
    }
    iterativePostorder(root);
    printf("Min: %d\n",findMin(root)->id);
    printf("Max: %d\n",findMax(root)->id);

    deleteNodeBST(root,root->id);

    printf("After deletion: \n");
    iterativePostorder(root);
    return 0;
}