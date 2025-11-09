// BST Operations:

// Create and display a BST.

// Find and display the second smallest number in the BST.

// Delete the node with a non-empty left subtree and empty right subtree.

// Find the difference between the number of nodes in the left and right subtrees.

#include<stdio.h>
#include<stdlib.h>


typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNewNode(int data){
    TreeNode* newNode= (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* createBST(TreeNode* root, int data){
    if(root==NULL){
        return createNewNode(data);
    }
    else if(data<root->data){
        root->left = createBST(root->left,data);
    }
    else if(data>root->data){
        root->right = createBST(root->right,data);
    }

    return root;
}

void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

TreeNode* deleteNodeBST(TreeNode* root, int target){
    if(root==NULL)return NULL;
    if(root->data==target){
        if(root->left!=NULL&&root->right==NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
    }
    else if(target<root->data){
        root->left = deleteNodeBST(root->left,target);
    }
    else if(target>root->data){
        root->right = deleteNodeBST(root->right,target);
    }
    return root;
}

int countNodes(TreeNode* root){
    if(root==NULL)return 0;
    int leftcount = countNodes(root->left);
    int rightcount = countNodes(root->right);
    return 1+leftcount+rightcount;
}

int i = 0;
void helper(TreeNode* root, int* arr){
    if(root==NULL)return;
    helper(root->left,arr);
    *(arr+i) = root->data;
    i++;
    helper(root->right,arr);
}

int kthSmallestElementBST(TreeNode* root, int k){
    if(root==NULL)return -1;
    int *arr = (int*)malloc(sizeof(int)*100);
    helper(root,arr);
    return *(arr+k-1);
}



int main(){
    int n,data;
    printf("Enter the number of nodes in bst: ");
    scanf("%d",&n);
    TreeNode* bstroot = NULL;
    for(int i=0; i<n; i++){
        printf("Enter an element: ");
        scanf("%d",&data);
        bstroot = createBST(bstroot,data);
    }
    printf("Differnece between number of nodes in left and right subtree: %d\n",(countNodes(bstroot->left)-countNodes(bstroot->right)));
    inorder(bstroot);
    printf("\n");
    deleteNodeBST(bstroot,20);
    inorder(bstroot);
    printf("\n");
    printf("2nd smallest element %d",kthSmallestElementBST(bstroot,2));
    return 0;
}