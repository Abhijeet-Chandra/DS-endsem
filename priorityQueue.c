#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char name[20];
    int age;
    int priority;
    struct Node* next;
}Node;

Node* createNode(char name[], int age, int priority){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->age = age;
    newNode->priority = priority;
    newNode->next= NULL;
    return newNode;
}

Node* front = NULL, *rear = NULL;

int isEmpty(){
    return front == NULL;
}

void enqueue(char name[], int age, int priority){
    Node* newNode = createNode(name,age,priority);
    if(!newNode){
        printf("Memory allocation failed.\n");
        return;
    }
    if(isEmpty()){
        front = rear = newNode;
        return;
    }

    if(front->priority>newNode->priority){
        newNode->next = front;
        front = newNode;
        return;
    }
    Node* temp = front, *temp1 = front;
    while(temp!=NULL){
        if(temp->priority>newNode->priority){
            newNode->next = temp;
            temp1->next = newNode;
            return;
        }
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = newNode;
    rear = newNode;
}

Node* dequeue(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return NULL;
    }
    Node* t = front;
    front = front->next;
    if (front==NULL) front=rear=NULL;
    return t;
}

Node* peek(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return NULL;
    }
    return front;
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return;
    }
    Node* temp = front;
    while(temp!=NULL){
        printf("Name: %s, ",temp->name);
        printf("Age: %d, ",temp->age);
        printf("Priority: %d",temp->priority);
        temp = temp->next;
        printf("\n");
    }
}

int main() {
    int choice, age, priority;
    char name[20];

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient name: ");
                scanf("%s", name);
                printf("Enter Patient age: ");
                scanf("%d", &age);
                printf("Enter Priority: ");
                scanf("%d", &priority );
                enqueue(name,age,priority);
                break;

            case 2:
                Node* returnval = dequeue();
                if (returnval!=NULL) {
                    printf("Dequeued: \n");
                    printf("Patient Name: %s\n",returnval->name);
                    printf("Patient Age: %d\n",returnval->age);
                    printf("Priority: %d\n",returnval->priority);
                    free(returnval);
                }
                break;

            case 3:
                Node* returnval1 = peek();
                if (returnval1!=NULL) {
                    printf("Patient Details: \n");
                    printf("Patient Name: %s\n",returnval1->name);
                    printf("Patient Age: %d\n",returnval1->age);
                    printf("Priority: %d\n",returnval1->priority);
                }
                break;

            case 4:
                printf("Queue contents:\n ");
                display();
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}