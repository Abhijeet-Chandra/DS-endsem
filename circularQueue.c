#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int currentsize = 0;
int front = -1, rear = -1;

int queue[MAX_SIZE];

int isEmpty(){
    return currentsize==0;
}

int isFull(){
    return currentsize == MAX_SIZE;
}

void enqueue(int data){
    if(isFull()){
        printf("Queue is Full.\n");
        return;
    }
    rear = (rear+1)%MAX_SIZE;
    queue[rear] = data;
    currentsize++;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return -1;
    }
    front = (front+1)%MAX_SIZE;
    currentsize--;
    return queue[front];
}

int peek(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return -1;
    }
    return queue[(front+1)%MAX_SIZE];
}


void display(){
    int counter = 0;
    for(int i = (front+1)%MAX_SIZE; ; i = (i+1)%MAX_SIZE){
        if(counter==currentsize)break;
        printf("%d ",queue[i]);
        counter++;        
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                data = peek();
                if (data != -1)
                    printf("Front element: %d\n", data);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}