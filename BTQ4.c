// Convert a Doubly Linked List (DLL) into a Binary Search Tree (BST) after performing the following DLL operations:

// Delete the nth node from the end.

// Create another DLL and append it to the updated first DLL.

// Delete duplicate nodes.

// Display the list.

// Convert the final DLL into a BST.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int size = 0;
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head1 = NULL, *tail1 = NULL;
Node* head2 = NULL, *tail2 = NULL;
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertLL(int data, Node**head, Node**tail){
    Node* newNode = createNode(data);
    if(*head==NULL){
        *head = *tail = newNode;
        size++;
        return;
    }
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
    size++;
}

Node* concatLL(){
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;

    tail1->next = head2;
    head2->prev = tail1;
    return head1;
}

void deleteNfromEnd(Node* head, Node* tail, int n){
    Node* temp = tail;
    if(n>=size){
        printf("insufficient list length.\n");
        return;
    }
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    int i = 0;
    while(i!=n){
        temp = temp->prev;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

Node* deleteDuplicates(){
    Node* temp1 = head1;
    Node* head3 = NULL, *tail3 = NULL;
    while(temp1!=NULL){
        bool flag = true;
        
        if(head3==NULL){
            Node* newNode = createNode(temp1->data);
            head3 = tail3 = newNode;
        }
        else{
            Node* temp2 = head3;
            while(temp2!=NULL){
                if(temp2->data==temp1->data){
                    flag = false;
                    break;
                }
                temp2 = temp2->next;
            }
            if(flag){
                Node* newNode = createNode(temp1->data);
                tail3->next = newNode;
                newNode->prev = tail3;
                tail3 = newNode;
            }
        }
        temp1 = temp1->next;
    }
    return head3;
}

void display(Node** head){
    Node* temp =*head;
    while(temp!=NULL){
        printf("%d<=>",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

TreeNode* DLLtoBST(TreeNode* root, int data){
    if(root==NULL){
        return createTreeNode(data);
    }
    else if(data<root->data){
        root->left = DLLtoBST(root->left,data);
    }
    else if(data>root->data){
        root->right = DLLtoBST(root->right,data);
    }
    return root;
}

void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    printf("Creating Linked List 1:\n");
    int n,ele;
    printf("Enter number of elements in linked list 1:\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter element: ");
        scanf("%d",&ele);
        insertLL(ele,&head1,&tail1);
    }
    display(&head1);

    deleteNfromEnd(head1,tail1,3);
    printf("After deletion: \n");
    display(&head1);

    printf("Enter number of elements in linked list 2:\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter element: ");
        scanf("%d",&ele);
        insertLL(ele,&head2,&tail2);
    }
    display(&head2);

    head1 = concatLL();
    display(&head1);
    
    Node* head3 = deleteDuplicates();
    display(&head3);
    printf("\n");
    Node* temp = head3;
    TreeNode* bstroot = NULL;
    while(temp!=NULL){
        bstroot = DLLtoBST(bstroot,temp->data);
        temp = temp->next;
    }
    inorder(bstroot);

}