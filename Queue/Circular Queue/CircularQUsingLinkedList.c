/*****************************************************************
Name    :CircularQUsingLinkedList
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190129 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *front=NULL;
Node *rear=NULL;

int isEmpty();
void push(int); 
int pop();

/*==============================================================*/
int isEmpty()
{
    return (front == NULL);
}

void push(int data)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    //push back
    if(rear == NULL){
        rear = new;
    }else{
        rear->next = new;
        rear = new;
    }

    if(front == NULL)
        front = new;
    rear->next = front;
}

int pop()
{
    if(isEmpty()){
        printf("Sequential Queue is Empty.\n");
        return -1;
    }

    //pop front
    Node *temp = front;
    int data = temp->data;
    front = temp->next;
    rear->next = front;
    free(temp);
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

    //check circular
    printf("next of rear is %d\n", rear->next->data);

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