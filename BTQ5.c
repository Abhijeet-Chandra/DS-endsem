// Implement a basic Spell Checker using BST where:

// The user inputs different words and stores them in a BST.

// Display the BST in inorder traversal.

// Take a word as input and search it in the BST.

// If found, check if it has a sibling and root.

// If sibling is present, print the sibling.

// If root is present, uppercase the middle letter of the word stored in the root.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct TreeNode{
    char str[20];
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTreeNode(char str[]){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->str,str);
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* createBST(TreeNode* root, char str[]){
    if(root==NULL){
        return createTreeNode(str);
    }
    else if(strcasecmp(str,root->str)<0){
        root->left = createBST(root->left,str);
    }
    else if(strcasecmp(str,root->str)>0){
        root->right = createBST(root->right,str);
    }
    return root;
}

void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%s ",root->str);
    inorder(root->right);
}

int search(TreeNode* root, char target []){
    if(root==NULL)return 0;
    if((root->left!=NULL&&(strcasecmp(root->left->str,target)==0))||(root->right!=NULL&&(strcasecmp(root->right->str,target)==0))){
        printf("FOUND!\n");
        if((root->left!=NULL&&(strcasecmp(root->left->str,target)==0))&&root->right){
            printf("Sibling: %s\n",root->right->str);
        }
        else if((root->right!=NULL&&(strcasecmp(root->right->str,target)==0))&&root->left){
            printf("Sibling: %s\n",root->left->str);
        }
        else printf("No sibling.\n");
        
        root->str[strlen(root->str)/2] = toupper(root->str[strlen(root->str)/2]);
        printf("Parent: %s",root->str);
        return 1;
    }

    if(strcasecmp(target,root->str)<0){
        return search(root->left,target);
    }
    else if(strcasecmp(target,root->str)>0){
        return search(root->right,target);
    }
    return 0;
}

int main(){
    TreeNode* bstroot = NULL;
    char str[20];
    for(int i=0; i<5; i++){
        printf("Enter word: ");
        scanf("%s",str);
        bstroot = createBST(bstroot,str);
    }
    inorder(bstroot);
    printf("\n");
    search(bstroot,"banana");
}