/*****************************************************************
Name    :binaryHeapUsingLinkedList
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190130 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*==============================================================*/
typedef struct treeNode
{
    struct treeNode *left;
    struct treeNode *right;
    int data;
}treeNode;

bool isEmpty();
void insert(int data);
int delete();

treeNode *root=NULL;
treeNode *last=NULL;

/*==============================================================*/
bool isEmpty()
{
    if(root == NULL){
        return true;
    }else{
        return false;
    }
}

void insert(int data)
{
    //new tree node
    treeNode *new = (treeNode*)malloc(sizeof(treeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    //handle the first insert
    if(root == NULL){
        root = new;
        last = new;
        return;
    }

    

}


/*==============================================================*/
int main(){
    printf("hello world\n");

    return 0;
}
/*==============================================================*/