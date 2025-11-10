#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top1 = NULL, *top2 = NULL;

int isEmpty(Node** top){
    return *top==NULL;
}

Node* createNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data,Node** top){
    Node* newNode = createNewNode(data);
    if(!newNode){
        printf("Memory allocation failed.\n");
        return;
    }
    if(isEmpty(&(*top))){
        *top = newNode;
        return;
    }
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top){
    if(isEmpty(&(*top))){
        printf("Empty.\n");
        return -1;
    }
    Node* t = *top;
    int returnvalue = (*top)->data;
    *top = (*top)->next;
    free(t);
    return returnvalue;
}

void enqueue(int data){
    while(!isEmpty(&top1)){
        push(pop(&top1),&top2);
    }
    push(data,&top1);
    while(!isEmpty(&top2)){
        push(pop(&top2),&top1);
    }
}

int dequeue(){
    if(isEmpty(&top1)){
        printf("Empty.\n");
        return -1;
    }
    return pop(&top1);
}

void display(Node**top){
    Node* temp = *top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek(){
    if(isEmpty(&top1)){
        printf("Empty.\n");
        return -1;
    }
    return top1->data;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display(&top1);
    dequeue();
    dequeue();
    dequeue();
    display(&top1);
    printf("%d\n",peek());
}