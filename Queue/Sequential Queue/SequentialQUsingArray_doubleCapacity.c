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
int *sequentialQ;

int front=0;
int rear=0;
int capacity=3;

int isEmpty();
int isFull();
void push(int); 
int pop();
void doubleCapacity();

/*==============================================================*/
int isEmpty()
{
    return (front == rear);
}

int isFull()
{
    return (rear == capacity);
}

void doubleCapacity()
{
    capacity *= 2;
    int *temp = sequentialQ;
    sequentialQ = (int*)malloc(sizeof(int) * capacity);
    printf("\nDouble the capacity : %d\n", capacity);

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
    sequentialQ = (int*)malloc(sizeof(int) * capacity);

    //push
    printf("Sequential Queue push : ");
    for(int i=0; i<10; i++){
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

    //push
    printf("Sequential Queue push : ");
    for(int i=0; i<5; i++){
        printf("%d ", i);
        push(i);
    }
    printf("\n");

    //pop
    printf("Queue pop : ");
    for(int i=0; i<10; i++){
        int temp = pop();
        if(temp != -1)
            printf("%d ", temp);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/
