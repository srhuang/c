/*****************************************************************
Name    :priorityQ_linkedList
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190128 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*==============================================================*/
// Node 
typedef struct node { 
    int data; 
    // Lower values indicate higher priority 
    int priority; 
    struct node *next; 
  
}Node;

/*==============================================================*/
//isEmpty()
//push()
//pop()
//peek()
bool isEmpty(Node **head)
{
    if(*head == NULL)
        return true;
    else
        return false;
}

void push(Node **head, Node *input)
{
    if(input == NULL)
        return;

    //for insert head case
    if(input->priority > (*head)->priority){
        Node *temp = *head;
        *head = input;
        (*head)->next = temp;
        return;
    }

    //for normal case
    Node *temp = (*head)->next;
    Node *pre = *head;
    while(temp != NULL && 
        (temp->priority > input->priority)){
        pre = temp;
        temp = temp->next;
    }
    pre->next = input;
    input->next = temp;
}

Node *pop(Node **head)
{
    Node *temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    return temp;
}

Node *peek(Node **head)
{
    return *head;
}

/*==============================================================*/
int main(){
    printf("hello world\n");

    //malloc head
    Node **head = (Node**)malloc(sizeof(Node*));
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = 50;
    temp->priority = 50;
    temp->next = NULL;
    *head = temp;

    printf("Generate data : ");
    for(int i=0; i<10; i++){
        int data = rand()%100;
        printf("%d ", data);
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->priority = data;
        temp->next = NULL;

        //push
        push(head, temp);
    }
    printf("\n");

    //trversal all priority queue
    printf("Traversal Priority Queue : ");
    Node *traversal=*head;
    while(traversal!=NULL){
        printf("%d ", traversal->data);
        traversal = traversal->next;
    }
    printf("\n");

    //pop data
    Node *answer = pop(head);
    printf("pop data : %d\n", answer->data);

    //trversal all priority queue
    printf("Traversal Priority Queue after pop : ");
    traversal=*head;
    while(traversal!=NULL){
        printf("%d ", traversal->data);
        traversal = traversal->next;
    }
    printf("\n");

    return 0;
}
/*==============================================================*/