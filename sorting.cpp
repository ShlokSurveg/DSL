#include <stdio.h>
#include <stdlib.h>

struct student{
    int roll;
    char name[20];
    float marks;
};

void bubbleSort(struct student a[], int n);
void selectionSort(struct student a[], int n);
void insertionSort(struct student a[], int n);
void display(struct student a[],int n);

int main(){
    int n;
    printf("Enter no of students : ");
    scanf("%d",&n);
    struct student a[n];
    printf("Enter Student Details : \n------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("Student %d Information :",i+1);
        printf("\nRoll No : ");
        scanf("%d", &a[i].roll);
        printf("Name : ");
        scanf("%s", a[i].name);
        printf("Marks : ");
        scanf("%f", &a[i].marks);

        printf("------------------------------------\n");
    }

    printf("Enter your choice of Sorting.\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n");
    int choice;
    scanf("%d",&choice);

    switch(choice){
        case 1:bubbleSort(a,n);
            break;
        case 2:insertionSort(a,n);
            break;
        case 3:selectionSort(a,n);
            break;
        default:printf("Invalid Input !");
            return -1;
    }
    display(a,n);
    return 0;
}

void display(struct student a[], int n){
    printf("The sorted array is as follows :\n");
    for(int i=0;i<n;i++){
        printf("Student No : %d\n",i+1);
        printf("Roll No : %d\n",a[i].roll);
        printf("Name : %s\n",a[i].name);
        printf("Marks : %f\n",a[i].marks);
        printf("---------------------------------\n");
    }
}

void bubbleSort(struct student a[],int n){
    struct student temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].marks>a[j+1].marks){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(struct student a[],int n){
    struct student temp;
    int minpos;
    for(int i=0;i<n-1;i++){
        minpos = 1;
        for(int j=0;j<i-1;j++){
            if(a[j].marks<a[minpos].marks)
                minpos = j;
        }
        if(minpos!=i){
            temp = a[i];
            a[i] = a[minpos];
            a[minpos] = temp;
        }
    }
}

void insertionSort(struct student a[],int n){
    struct student key;
    int j;
    for(int i=1;i<n;i++){
        key = a[i];
        j=i-1;
        while(j>=0 && a[j].marks>key.marks){
            a[j+1] = a[j];
            j--;
        }
    a[j+1] = key;
    }
}