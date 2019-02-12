/*****************************************************************
Name    :stackUsingArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190212 Support multi-stack
    20190125 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
typedef struct stack{
    int size;
    int *container;
    int top;
}stack;

stack* newStack(int);
void deleteStack(stack*);
int isEmpty(stack*);
void push(int, stack*); 
int pop(stack*);

/*==============================================================*/
stack* newStack(int size)
{
    if(size<=0)
        return NULL;
    stack *ret = malloc(sizeof(stack));
    ret->size = size;
    ret->container = malloc(sizeof(int) * size);
    ret->top = -1;

    return ret;
}

void deleteStack(stack *myStack){
    free(myStack->container);
    free(myStack);
}

int isEmpty(stack *myStack)
{
    if(myStack->top==-1){
        return 1; 
    }else{
        return 0;
    }
}

void push(int data, stack *myStack)
{
    if(myStack->top >= myStack->size){
        printf("Stack is FULL\n"); 
    }else{
        myStack->top++;
        myStack->container[myStack->top]=data;
    }
}

int pop(stack *myStack)
{
    int data;
    if(isEmpty(myStack)){
        printf("Stack is empty\n");
        return -1;
    }else{
        data=myStack->container[myStack->top];
        myStack->top--;
        return data; 
    }
}

/*==============================================================*/
int main(){
    //new stack
    int size = 100;
    stack *myStack = newStack(size);

    //push
    for(int i=0; i<10; i++){
        push(i, myStack);
    }

    //pop
    printf("Stack pop : ");
    for(int i=0; i<10; i++){
        int temp = pop(myStack);
        printf("%d ", temp);
    }
    printf("\n");

    //free stack
    deleteStack(myStack);
    return 0;
}
/*==============================================================*/