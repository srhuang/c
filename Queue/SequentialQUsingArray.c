/*****************************************************************
Name    :SequentialQUsingArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190129 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
#define MAXSIZE (10)
int sequentialQ[MAXSIZE];
int isEmpty();
int isFull();
void push(int); 
int pop();
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

void push(int data)
{
    if(isFull()){
        printf("Sequential Queue is Full.\n");
        return;
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
    //push
    printf("Sequential Queue push : ");
    for(int i=0; i<10; i++){
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

    //push
    printf("Sequential Queue push : ");
    for(int i=0; i<5; i++){
        printf("%d ", i);
        push(i);
    }

    return 0;
}
/*==============================================================*/
