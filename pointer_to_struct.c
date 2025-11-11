#include<stdio.h>
#include<stdlib.h>

struct Student{
    char name[50];
    int roll_no;
    float marks;
};

void read(struct Student* stu, int n){
    for(int i = 0; i<n; i++){
        printf("Enter name of student %d: ", i+1);
        scanf("%s",(stu+i)->name);
        printf("Enter roll no of student %d: ",i+1);
        scanf("%d",&((stu+i)->roll_no));
        printf("Enter marks of student %d: ",i+1);
        scanf("%f",&((stu+i)->marks));
    }
}

void display(struct Student* stu, int n){
    for(int i = 0; i<n; i++){
        printf("Name of student %d: ", i+1);
        printf("%s\n",(stu+i)->name);
        printf("Roll no of student %d: ",i+1);
        printf("%d\n",((stu+i)->roll_no));
        printf("Marks of student %d: ",i+1);
        printf("%f\n",((stu+i)->marks));
    }
}

void displayHighest(struct Student* stu, int n){
    float highest = stu->marks;
    int pos = 0;
    for(int i=0; i<n; i++){
        if((stu+i)->marks>highest){
            highest = (stu+i)->marks;
            pos = i;
        }
    }

        printf("Details of student with highest marks: \n");
        printf("Name of student %d: ", pos+1);
        printf("%s\n",(stu+pos)->name);
        printf("Roll no of student %d: ",pos+1);
        printf("%d\n",((stu+pos)->roll_no));
        printf("Marks of student %d: ",pos+1);
        printf("%f\n",((stu+pos)->marks));
}

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct Student* stu = (struct Student*)malloc(n*(sizeof(struct Student)));
    read(stu,n);
    display(stu,n);
    displayHighest(stu,n);
    free(stu);
}