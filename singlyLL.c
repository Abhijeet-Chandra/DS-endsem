// Insert an element before another specified element in the list
// (Example: Insert 10 before 25)
// ➢ Insert an element after another specified element in the list
// (Example: Insert 40 after 25)
// ➢ Delete a specified element from the list
// (Example: Delete node containing 15)
// ➢ Traverse the list and display all elements
// ➢ Reverse the linked list
// (Modify the links such that the list is reversed)
// ➢ Sort the list in ascending order
// (Using Bubble Sort or any appropriate algorithm on linked list)
// ➢ Delete every alternate node in the list
// (Starting from the second node)
// ➢ Insert an element into a sorted linked list while maintaining the sorted order
// (Example: Insert 28 into a list that is already sorted)

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int size = 0;
Node* head = NULL;


void createLL(int data){
    Node* newNode = createNode(data);
    if(head==NULL){
        head = newNode;
        size++;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

void insertBefore(int data, int target){
    Node* newNode = createNode(data);
    if(head==NULL){
        printf("List is empty.Add elements first using createLL() function\n");
        return;
    }
    if(head->data==target){
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==target){
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
            return;
        }
        temp = temp->next;
    }
}

void insertAfter(int data, int target){
    Node* newNode = createNode(data);
    if(head==NULL){
        printf("List is empty.Add elements first using createLL() function\n");
        return;
    }
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==target){
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
            return;
        }
        temp = temp->next;
    }
}

void displayLL(){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(int target){
    if(head==NULL){
        printf("List Is empty.\n");
        return;
    }
    if(head->data==target){
        Node* t = head;
        head = head->next;
        free(t);
        size--;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==target){
            Node* t = temp->next;
            temp->next = temp->next->next;
            free(t);
            size--;
            return;
        }
        temp = temp->next;
    }
}

void reverseLL(){
    Node* temp = head, *prev = NULL, * front = NULL;
    while(temp!=NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    head = prev;
    printf("LL reversed.\n");
}

void sortLL(){
    Node* i, *j;
    for(i = head; i!=NULL; i = i->next){
        for(j = head; j!=NULL; j = j->next){
            if(i->data<j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void deleteAlternate(){
    Node* temp = head;
    while(temp != NULL&&temp->next!=NULL){
        Node* t = temp->next;
        temp->next = temp->next->next;
        free(t);
        size--;
        temp = temp->next;
    }
}

void insertSorted(int data){
    if(head==NULL){
        printf("List is empty.Add elements first using createLL() function\n");
        return;
    }
    Node* newNode = createNode(data);
    sortLL();
    if(head->data>data){
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }
    Node* temp = head;
    
    while(temp->next!=NULL){
        if(temp->next->data>data){
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
            return;
        }
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

int main(){
    createLL(10);
    createLL(30);
    createLL(40);
    createLL(60);
    displayLL();
    insertAfter(20,10);
    insertAfter(50,40);
    insertAfter(70,60);
    displayLL();
    deleteNode(40);
    deleteNode(60);
    deleteNode(10);
    displayLL();
    reverseLL();
    displayLL();
    deleteAlternate();
    displayLL();
    sortLL();
    displayLL();
    insertSorted(50);
    insertSorted(80);
    displayLL();
}