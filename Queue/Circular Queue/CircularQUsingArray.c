/*****************************************************************
Name    :CircularQUsingArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190129 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
#define MAXSIZE (10)
int circularQ[MAXSIZE];

int front=-1;
int rear=-1;

int isEmpty();
int isFull();
void push(int); 
int pop();

/*==============================================================*/
int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return ((rear+1)%MAXSIZE == front);
}

void push(int data)
{
    if(isFull()){
        printf("(%d)Circular Queue is Full.\n", data);
        return;
    }

    //push back
    if(-1 == front)
        front = 0;
    rear = (rear+1) % MAXSIZE;
    circularQ[rear] = data;
}

int pop()
{
    if(isEmpty()){
        printf("Circular Queue is Empty.\n");
        return -1;
    }

    //pop front
    int data = circularQ[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front+1) % MAXSIZE;
    }
    return data;
}

/*==============================================================*/
int main(){
        //push
    printf("Circular Queue push : ");
    for(int i=0; i<10; i++){
        printf("%d ", i);
        push(i);
    }
    printf("\n");

    //pop
    printf("Circular Queue pop : ");
    for(int i=0; i<5; i++){
        int temp = pop();
        if(temp != -1)
            printf("%d ", temp);
    }
    printf("\n");

    //push
    printf("Circular Queue push : ");
    for(int i=0; i<5; i++){
        printf("%d ", i);
        push(i);
    }
    printf("\n");

    //pop
    printf("Circular Queue pop : ");
    for(int i=0; i<10; i++){
        int temp = pop();
        if(temp != -1)
            printf("%d ", temp);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/