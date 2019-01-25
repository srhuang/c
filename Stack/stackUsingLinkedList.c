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

Node *top=NULL;
int isEmpty();
void push(int); 
int pop();

/*==============================================================*/
int isEmpty(){
    if(top==NULL){
        return 1; 
    }else{
        return 0;
    }
}

void push(int data){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = top;
    top = new;
}

int pop(){

    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    }else{
        Node *temp = top;
        int data = temp->data;
        top = temp->next;
        free(temp);
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