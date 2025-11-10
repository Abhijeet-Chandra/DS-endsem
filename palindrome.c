#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];

int top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX_SIZE-1;
}

void push(char c){
    if(isFull()){
        printf("Stackoverflow.FUCK OFF.\n");
        return;
    }
    stack[++top] = c;
}

char pop(){
    if(isEmpty()){
        printf("Stackunderflow.FUCK OFF.\n");
        return '\0';
    }
    return stack[top--];
}

char peek(){
    if(isEmpty()){
        printf("Stackunderflow.FUCK OFF.\n");
        return '\0';
    }
    return stack[top];
}

int main(){
    char str[100];
    printf("Enter a string.\n");
    scanf("%s",str);
    for(int i = 0; i<strlen(str); i++){
        push(str[i]);
    }
    for(int i = 0; i<strlen(str); i++){
        if(str[i]!=pop()){
            printf("Not a palindrome.\n");
            return 0;
        }
    }
    printf("It is a palindrome.\n");
    return 0;
}