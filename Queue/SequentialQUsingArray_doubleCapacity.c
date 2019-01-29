/*****************************************************************
Name    :SequentialQUsingArray_doubleCapacity
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190129 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
#define MAXSIZE (10)
int *sequentialQ;
int isEmpty();
int isFull();
void push(int); 
int pop();
void doubleCapacity();
int front=0;
int rear=0;

/*==============================================================*/
int isEmpty()
{
    return (front == rear);
}

int isFull()
{
    return (rear == MAXSIZE);
}

void doubleCapacity()
{
    int capacity = sizeof(sequentialQ)/sizeof(int);
    int *temp = sequentialQ;
    sequentialQ = (int*)malloc(sizeof(int) * capacity * 2);
    printf("\nDouble the capacity.\n");

    //copy the data
    int index=0;
    for(int i=front; i<rear; i++){
        sequentialQ[index++] = temp[i];
    }
    front = 0;
    rear = index;
    free(temp);
}

void push(int data)
{
    if(isFull()){
        //printf("Sequential Queue is Full.\n");
        doubleCapacity();
    }

    //push back
    sequentialQ[rear++] = data;
}

int pop()
{
    if(isEmpty()){
        printf("Sequential Queue is Empty.\n");
        return -1;
    }

    //pop front
    return sequentialQ[front++];
}

/*==============================================================*/
int main(){
    //initialize queue
    sequentialQ = (int*)malloc(sizeof(int) * MAXSIZE);

    //push
    printf("Sequential Queue push : ");
    for(int i=0; i<15; i++){
        printf("%d ", i);
        push(i);
    }
    printf("\n");

    //pop
    printf("Queue pop : ");
    for(int i=0; i<15; i++){
        int temp = pop();
        if(temp != -1)
            printf("%d ", temp);
    }
    printf("\n");

    //push
    printf("Sequential Queue push : ");
    for(int i=0; i<5; i++){
        printf("%d ", i);
        push(i);
    }
    printf("\n");

    //pop
    printf("Queue pop : ");
    for(int i=0; i<5; i++){
        int temp = pop();
        if(temp != -1)
            printf("%d ", temp);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/
