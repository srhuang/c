/*****************************************************************
Name    :stackUsingArray_doubleCapacity
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190129 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
int *stack;
int top=-1;
int capacity=3;
int isEmpty();
void push(int); 
int pop();

/*==============================================================*/
int isEmpty(){
    if(top==-1){
        return 1; 
    }else{
        return 0;
    }
}

void doubleCapacity()
{
    capacity *= 2;
    int *temp = stack;
    stack = (int*)malloc(sizeof(int) * capacity);
    printf("\nDouble the capacity : %d.\n", capacity);

    //copy the data
    for(int i=0; i<=top; i++){
        stack[i] = temp[i];
    }
    free(temp);
}

void push(int data){
    if(top>capacity){
        //printf("Stack is FULL\n"); 
        doubleCapacity();

    }
    top++;
    stack[top]=data;

}

int pop(){
    int data;
    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    }else{
        data=stack[top];
        top--;
        return data; 
    }
}

/*==============================================================*/
int main(){
    //Initialize
    stack = (int*)malloc(sizeof(int) * capacity);

    //push
    for(int i=0; i<12; i++){
        push(i);
    }

    //pop
    printf("Stack pop : ");
    for(int i=0; i<12; i++){
        int temp = pop();
        printf("%d ", temp);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/