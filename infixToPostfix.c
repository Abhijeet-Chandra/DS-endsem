#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* top = NULL;

int isEmpty(){
    return top==NULL;
}

Node* createNode(char c){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = NULL;
    return newNode;
}

void push(char c){
    Node* newNode = createNode(c);
    if(!newNode){
        printf("Memory Allocation failed.\n");
        return;
    }

    if(isEmpty()){
        top = newNode;
        return;
    }

    newNode->next = top;
    top = newNode;
}

char pop(){
    if(isEmpty()){
        printf("Stack underflow.FUCK OFF!");
        return '\0';
    }
    Node* t = top;
    char returnvalue = top->data;
    top = top->next;
    free(t);
    return returnvalue;
}
char peek(){
    if(isEmpty()){
        printf("Stack underflow.FUCK OFF!");
        return '\0';
    }
    return top->data;
}

int precedence(char symbol){
    switch(symbol){
        case '^': return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default: return 0;        
    }
}

int associativity(char symbol){
    switch(symbol){
        case '*':
        case '/':
        case '+':
        case '-':
            return 1; //L to R
        case '^':
            return 0; //R to L
        default: return -1;
    }
}

int main(){
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s",infix);
    char postfix[100];
    int k = 0;
    for(int i=0; i<strlen(infix); i++){
        switch(infix[i]){
            case '(': push(infix[i]);
                break;
            case ')':
                while(!isEmpty()&&peek()!='('){
                    postfix[k++] = pop();      
                }
                pop();
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                if(associativity(infix[i])){
                    while(!isEmpty()&&(precedence(infix[i])<=precedence(peek()))){
                        postfix[k++] = pop();
                    }
                }
                else{
                    while(!isEmpty()&&(precedence(infix[i])<precedence(peek()))){
                        postfix[k++] = pop();
                    }
                }
                push(infix[i]);
                break;
            default: postfix[k++] = infix[i];        
        }
    }
    while(!isEmpty()){
            postfix[k++] = pop();
        }
        postfix[k] = '\0';

        printf("Postfix expression: %s",postfix);
}