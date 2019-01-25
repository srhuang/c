/*****************************************************************
Name    :stackUsingArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190125 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
#define MAXSTACK (100)
int stack[MAXSTACK];
int top=-1;
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

void push(int data){
    if(top>=MAXSTACK){
        printf("Stack is FULL\n"); 
    }else{
        top++;
        stack[top]=data;
    }
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
    //push
    for(int i=0; i<10; i++){
        push(i);
    }

    //pop
    printf("Stack pop : ");
    for(int i=0; i<10; i++){
        int temp = pop();
        printf("%d ", temp);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/