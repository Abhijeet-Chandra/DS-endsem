#include<stdio.h>
#include<stdlib.h>
struct Student{
    char name[20];
    int roll_no;
    char grade;
};

void read(struct Student stu[], int n){
    for(int i = 0; i<n; i++){
        printf("Enter name of student %d: ",i+1);
        scanf("%s",stu[i].name);
        printf("Enter roll_no of student %d: ",i+1);
        scanf("%d",&stu[i].roll_no);
        printf("Enter grade of student %d: ",i+1);
        scanf(" %c",&stu[i].grade);
    }
}

void display(struct Student stu[], int n){
    for(int i = 0; i<n; i++){
        printf("Name of student %d: ",i+1);
        printf("%s\n",stu[i].name);
        printf("Roll_no of student %d: ",i+1);
        printf("%d\n",stu[i].roll_no);
        printf("Grade of student %d: ",i+1);
        printf("%c\n",stu[i].grade);
    }
    printf("\n");
}

void sort(struct Student stu[], int n){
    for(int i=0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            if(stu[j].roll_no>stu[j+1].roll_no){
                struct Student temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }
    printf("Sorted Students: \n");
    display(stu,n);
}

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student stu[n];
    read(stu,n);
    display(stu,n);
    sort(stu,n);

}