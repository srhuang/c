/*****************************************************************
Name    :stackUsingLinkedList
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190125 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct stack{
    Node *top;
}stack;

stack* newStack();
void deleteStack(stack *);
int isEmpty(stack*);
void push(int, stack*); 
int pop(stack*);
int peek(stack*);

/*==============================================================*/
stack* newStack()
{
    stack *ret = malloc(sizeof(stack));
    ret->top = NULL;

    return ret;
}

void deleteStack(stack *myStack)
{
    while(myStack->top != NULL){
        pop(myStack);
    }
    free(myStack);
}

int isEmpty(stack *myStack){
    if(myStack->top==NULL){
        return 1; 
    }else{
        return 0;
    }
}

void push(int data, stack *myStack){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = myStack->top;
    myStack->top = new;
}

int pop(stack *myStack){

    if(isEmpty(myStack)){
        printf("Stack is empty\n");
        return -1;
    }else{
        Node *temp = myStack->top;
        int data = temp->data;
        myStack->top = temp->next;
        free(temp);
        return data;
    }

}

int peek(stack *myStack)
{
    if(isEmpty(myStack)){
        return -1;
    }else{
        return myStack->top->data;
    }
}

/*==============================================================*/
int main(){
    stack *myStack = newStack();
    //push
    for(int i=0; i<10; i++){
        push(i, myStack);
    }

    //pop
    printf("Stack pop : ");
    for(int i=0; i<5; i++){
        int temp = pop(myStack);
        printf("%d ", temp);
    }
    printf("\n");

    int temp = peek(myStack);
    printf("%d ", temp);

    deleteStack(myStack);
    return 0;
}
/*==============================================================*/