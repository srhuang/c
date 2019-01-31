/*****************************************************************
Name    :binaryHeap
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190130 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
//Tree Node
typedef struct treeNode
{
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *parent;
    int data;
}treeNode;

treeNode *root=NULL;

void heapifyUp(treeNode*);
void heapifyDown();
void insert(int data);
int extract();

//Queue Node
typedef struct queueNode{
    treeNode *data;
    struct queueNode *next;
}queueNode;

queueNode *front=NULL;
queueNode *rear=NULL;

int isEmpty();
void enqueue(treeNode*); 
treeNode* dequeue();

/*==============================================================*/
//Queue operation
int isEmpty()
{
    return (front == NULL);
}

void enqueue(treeNode *data)
{
    queueNode *new = (queueNode*)malloc(sizeof(queueNode));
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
}

treeNode* dequeue()
{
    if(isEmpty()){
        printf("Sequential Queue is Empty.\n");
        return NULL;
    }

    //pop front
    queueNode *temp = front;
    treeNode *data = temp->data;
    front = temp->next;
    free(temp);
    return data;
}

//tree operation
void insert(int data){
    //printf("Tree insert %d\n", data);
    treeNode *new = (treeNode*)malloc(sizeof(treeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    //Queue contain the tree node which is not complete.
    if(root == NULL){
        root = new;
    }else{
        //get from queue
        treeNode *temp = front->data;
        //printf("peek the front : %d\n", temp->data);

        if(temp->left == NULL){
            temp->left = new;
            new->parent = temp;
        }else if(temp->right == NULL){
            temp->right = new;
            new->parent = temp;
        }else{
            dequeue();
            temp = front->data;
            temp->left = new;
            new->parent = temp;
        }
    }

    //enqueue the tree node
    enqueue(new);
    heapifyUp(new);
}

void heapifyUp(treeNode *leaf){
    if(leaf == root)
        return;

    treeNode *parent = leaf->parent;
    if(leaf->data < parent->data){
        int temp = parent->data;
        parent->data = leaf->data;
        leaf->data = temp;
        heapifyUp(parent);
    }
}

//traversal
void preorderTraversal(treeNode *parent)
{
    if(parent == NULL)
        return;

    printf("%d ", parent->data);
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void inorderTraversal(treeNode *parent)
{
    if(parent == NULL)
        return;

    inorderTraversal(parent->left);
    printf("%d ", parent->data);
    inorderTraversal(parent->right);
}

void postorderTraversal(treeNode *parent)
{
    if(parent == NULL)
        return;

    postorderTraversal(parent->left);
    postorderTraversal(parent->right);
    printf("%d ", parent->data);
}

/*==============================================================*/
int main(){
    int test[10]={9,8,7,6,5,4,3,2,1,0};
    int size = sizeof(test)/sizeof(int);
    printf("size is : %d\n", size);

    for(int i=0; i<size; i++){
        insert(i);
    }

    //traverse and print the tree
    printf("Preorder Traversal : ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal : ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal : ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
/*==============================================================*/