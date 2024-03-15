#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student{
    int rollno;
    char name[50];
    int marks1;
    int marks2;
    int marks3;
    int marks4;
    int marks5;
    int totalmarks;
}st;

FILE *fp;
int num=0;

void add_student(){
    fp= fopen("student.txt", "ab");

    printf("enter name: ");
    scanf("%s", &st.name);

    printf("enter rollno: ");
    scanf("%d", &st.rollno);

    int sum=0;
    int i=0;
    printf("enter marks1: ");
    scanf("%d", &st.marks1);
    printf("enter marks2: ");
    scanf("%d", &st.marks2);
    printf("enter marks3: ");
    scanf("%d", &st.marks3);
    printf("enter marks4: ");
    scanf("%d", &st.marks4);
    printf("enter marks5: ");
    scanf("%d", &st.marks5);
    st.totalmarks= st.marks1+ st.marks2+st.marks3+st.marks4+st.marks5;

    printf("student added successfully...\n");
    num++;
    fwrite(&st, sizeof(st),1, fp);
    fclose(fp);
}

void update_marks(){
    int roll_no,f;

    printf("\n-----Update marks-----\n");
    printf("enter rollno to update: ");
    scanf("%d", &roll_no);

    fp= fopen("student.txt", "rb+");

    while(fread(&st, sizeof(st), 1,fp)==1){
        if(roll_no ==st.rollno){
            f=1;
            printf("enter the new set of marks\n");
            int i=0;
            st.totalmarks=0;
            printf("enter marks1: ");
            scanf("%d", &st.marks1);
            printf("enter marks2: ");
            scanf("%d", &st.marks2);
            printf("enter marks3: ");
            scanf("%d", &st.marks3);
            printf("enter marks4: ");
            scanf("%d", &st.marks4);
            printf("enter marks5: ");
            scanf("%d", &st.marks5);
            st.totalmarks= st.marks1+ st.marks2+st.marks3+st.marks4+st.marks5;    

            fseek(fp, -sizeof(st),1);
            fwrite(&st, sizeof(st),1,fp);
            fclose(fp);
            break;
        }
    }

    if(f==1){
        printf("\nMarks updated successfully...\n");

    }
    else{
        printf("\nStudent not found...\n");
    }

}

void display(){
    system("cls");
    printf("\n---Student details----\n");
    printf("%-10s %-30s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Rollno", "Name" ,"Marks1", "Marks2", "Marks3", "Marks4", "Marks5", "Total Marks");

    fp= fopen("student.txt", "rb");
    while(fread(&st, sizeof(st), 1, fp)==1){
        printf("%-10d %-30s %-20d %-20d %-20d %-20d %-20d %-20d\n", st.rollno, st.name, st.marks1,st.marks2, st.marks3, st.marks4, st.marks5, st.totalmarks);

    }
    fclose(fp);
}

void teacher(){
    int val;
    printf("\n1. add student\n");
    printf("2. update marks\n");
    printf("3. display marks\n");

    printf("enter choice: ");
    scanf("%d", &val);

    switch(val){
        case 1: add_student();
                break;
        case 2: update_marks();
                break;
        case 3: display();
                break;
        default: printf("invalid input\n");
    }
}
/*
void display_result(){
    fp= fopen("student.txt", "rb+");
    struct Student student_arr[num];
    int k=0;   
    while(fread(&st, sizeof(st), 1,fp)==1){
        //struct Student newstudent=


        newstudent.rollno= st.rollno;
        newstudent.name= st.name;
        newstudent.marks1=st.marks1;
        newstudent.marks2=st.marks2;
        newstudent.marks3=st.marks3;
        newstudent.marks4=st.marks4;
        newstudent.marks5=st.marks5;
        newstudent.totalmarks=st.totalmarks;

        //student_arr[k++]={st.rollno, st.name, st.marks1,st.marks2, st.marks3, st.marks4, st.marks5, st.totalmarks};

    }

    fclose(fp);
    int i,j;
    for (i = 0; i < num- 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (student_arr[j].totalmarks < student_arr[j + 1].totalmarks) {
                struct Student temp = student_arr[j];
                student_arr[j] = student_arr[j + 1];
                student_arr[j + 1] = temp;
            }
        }
    }

    printf("\nAll Student Details Sorted by Total Marks:\n");
    printf("%-10s %-30s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Rollno", "Name" ,"Marks1", "Marks2", "Marks3", "Marks4", "Marks5", "Total Marks");
    for (i = 0; i < num; i++) {
          printf("%-10d %-30s %-20d %-20d %-20d %-20d %-20d %-20d\n", student_arr[i].rollno, student_arr[i].name, student_arr[i].marks1,student_arr[i].marks2, student_arr[i].marks3, student_arr[i].marks4, student_arr[i].marks5, student_arr[i].totalmarks);

    }
}
*/

void student(){
    display();
}

int main(){
    int val;

    while(1){
        printf("\n1. teacher\n");
        printf("2. student\n");
        printf("0. exit\n");

        printf("enter choice: ");
        scanf("%d", &val);

        switch(val){
            case 1: teacher();
                    break;
            case 2: student();
                    break;
            case 0: exit(0);
            default: printf("invalid input\n");
        }
    }
}