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
typedef struct stack{
    int size;
    int *container;
    int top;
}stack;

stack* newStack(int);
void doubleCapacity(stack *);
void deleteStack(stack*);
int isEmpty(stack*);
void push(int, stack*); 
int pop(stack*);
int peek(stack*);
int size(stack*);

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

void doubleCapacity(stack *myStack)
{
    myStack->size *= 2;
    myStack->container = (int*)realloc(myStack->container, sizeof(int) * (myStack->size));
    printf("\nDouble the capacity : %d.\n", myStack->size);
}

int size(stack *myStack)
{
    return myStack->top+1;
}

void push(int data, stack *myStack){
    if(myStack->top >= myStack->size){
        //printf("Stack is FULL\n"); 
        doubleCapacity(myStack);

    }
    myStack->top++;
    myStack->container[myStack->top]=data;
    
}

int pop(stack *myStack){
    int data;
    if(isEmpty(myStack)){
        printf("Stack is empty\n");
        return -1;
    }else{
        data=myStack->container[myStack->top];
        myStack->top--;
        //printf("pop %d\n", data);
        return data; 
    }
}

int peek(stack *myStack)
{
    int data;
    if(isEmpty(myStack)){
        //printf("Stack is empty\n");
        return -1;
    }else{
        data=myStack->container[myStack->top];
        return data; 
    }
}

/*==============================================================*/
int main(){
    //Initialize
    stack *myStack = newStack(10);

    //push
    for(int i=0; i<12; i++){
        push(i, myStack);
    }

    //pop
    printf("Stack pop : ");
    for(int i=0; i<12; i++){
        int temp = pop(myStack);
        printf("%d ", temp);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/