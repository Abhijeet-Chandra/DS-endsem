#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

Node* head = NULL;
int size = 0;


void insertAtRear(int data){
    Node* newNode = createNewNode(data);
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
    newNode->prev = temp;
    size++;
}

void insertAtFront(int data){
    Node* newNode = createNewNode(data);
    if(head==NULL){
        head = newNode;
        size++;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    size++;
}

void deleteFromFront(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(t);
    size--;
}


void deleteFromRear(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    if(head->next==NULL){
        Node* t = head;
        head = NULL;
        free(t);
        size--;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    size--;
    free(temp);
}

void insertAtIndex(int data,int index){
    if(index<0||index>size){
        printf("Enter a valid index.\n");
        return;
    }
    if(index==0){
        insertAtFront(data);
        return;
    }
    if(index == size){
        insertAtRear(data);
        return;
    }
    Node* newNode = createNewNode(data);
    Node* temp = head;
    int counter = 0;
    while(temp!=NULL){
        if(counter==index){
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            size++;
            return;
        }
        temp = temp->next;
        counter++;
    }
}

void deleteFromIndex(int index){
    if(index<0||index>=size){
        printf("Enter a valid index.\n");
        return;
    }
    if(index==0){
        deleteFromFront();
        return;
    }
    if(index == size-1){
        deleteFromRear();
        return;
    }
    Node* temp = head;
    int counter = 0;
    while(temp!=NULL){
        if(counter==index){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            size--;
            return;
        }
        temp = temp->next;
        counter++;
    }
}

void display(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while(temp!=NULL){
        printf("%d<=>",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayReverse(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    while(temp!=NULL){
        printf("%d<=>",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    insertAtRear(0);
    insertAtRear(10);
    insertAtRear(20);
    insertAtRear(30);
    insertAtRear(40);
    display();
    deleteFromRear();
    display();
    insertAtIndex(19,0);
    display();
    deleteFromIndex(2);
    display();
    displayReverse();
}