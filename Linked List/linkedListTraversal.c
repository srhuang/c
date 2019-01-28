/*****************************************************************
Name    :linkedListTraversal
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190102 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
typedef struct Node{
    int data;
    struct Node *next;
}Node;

/*==============================================================*/
Node* arrayToLinkedList(int* array, int num){
    printf("Array to linked list : ");
    printf("%d\t", array[0]);
    Node *head = malloc(sizeof(Node));
    head->data = array[0];
    head->next = NULL;

    Node *pre = head;
    for(int i=1; i<num; i++){
        printf("%d\t", array[i]);
        Node *current = malloc(sizeof(Node));
        pre->next = current;
        current->data = array[i];
        current->next = NULL;
        pre = current;
    }
    printf("\n");

    return head;
}

/*==============================================================*/
int main(){
    Node *head = NULL;
    int test_data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    head = arrayToLinkedList(test_data, sizeof(test_data)/sizeof(int));

    //traversal and print all linked list
    printf("Print all data in linked list : ");
    Node *temp = head;
    while(NULL != temp){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
/*==============================================================*/