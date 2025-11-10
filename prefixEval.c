#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

int isEmpty(){
    return top == NULL;
}

Node* createNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data){
    Node* newNode = createNewNode(data);
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

int pop(){
    if(isEmpty()){
        printf("Stack underflow.\n");
        return -1;
    }
    Node* t = top;
    int returnvalue = top->data;
    top = top->next;
    free(t);
    return returnvalue;
}

int peek(){
    if(isEmpty()){
        printf("Stack underflow.\n");
        return -1;
    }
    return top->data;
}

int main(){
    char prefix[100];
    printf("Enter prefix expression: ");
    scanf("%s",prefix);
    for(int i=strlen(prefix)-1; i>=0; i--){
        switch(prefix[i]){
            int op_top, op_bottom;
            case '*':
                op_top = pop();
                op_bottom = pop();
                push(op_top*op_bottom);
                break;
            case '/':
                op_top = pop();
                op_bottom = pop();
                push(op_top/op_bottom);
                break;
            case '+':
                op_top = pop();
                op_bottom = pop();
                push(op_top+op_bottom);
                break;
            case '-':
                op_top = pop();
                op_bottom = pop();
                push(op_top-op_bottom);
                break;        
            case '^':
                op_top = pop();
                op_bottom = pop();
                push(pow(op_top,op_bottom));
                break;
            default:
                push(prefix[i]-'0');
        }
    }
    
    printf("After evaluation: %d",pop());
    return 0;
}