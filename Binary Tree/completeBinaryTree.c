/*****************************************************************
Name    :completeBinaryTree
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190130 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
//Tree Node
struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int data;
};

//Queue Node
struct queueNode{
    struct TreeNode *data;
    struct queueNode *next;
};

struct queue{
    struct queueNode *front;
    struct queueNode *rear;
};

int isEmpty(struct queue *q);
void enqueue(struct queue **q, struct TreeNode*); 
struct TreeNode* dequeue(struct queue **q);

void insert(struct TreeNode **root, struct queue **q, int data);

/*==============================================================*/
//Queue operation
int isEmpty(struct queue *q)
{
    return (q->front == NULL);
}

void enqueue(struct queue **q, struct TreeNode *data)
{
    struct queueNode *new = (struct queueNode*)malloc(sizeof(struct queueNode));
    new->data = data;
    new->next = NULL;
    //push back
    if((*q)->rear == NULL){
        (*q)->rear = new;
    }else{
        (*q)->rear->next = new;
        (*q)->rear = new;
    }

    if((*q)->front == NULL)
        (*q)->front = new;
}

struct TreeNode* dequeue(struct queue **q)
{
    if(isEmpty(*q)){
        printf("Sequential Queue is Empty.\n");
        return NULL;
    }

    //pop front
    struct queueNode *temp = (*q)->front;
    struct TreeNode *data = temp->data;
    (*q)->front = temp->next;
    free(temp);
    return data;
}

//tree operation
void insert(struct TreeNode **root, struct queue **q, int data){
    printf("Tree insert %d\n", data);
    struct TreeNode *new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    //Queue contain the tree node which is not complete.
    if(*root == NULL){
        *root = new;
    }else{
        //get from queue
        struct TreeNode *temp = (*q)->front->data;
        printf("peek the front : %d\n", temp->data);

        if(temp->left == NULL){
            temp->left = new;
        }else{
            temp->right = new;
            dequeue(q);
        }
    }

    //enqueue the tree node
    enqueue(q, new);
}

//traversal
void preorderTraversal(struct TreeNode *parent)
{
    if(parent == NULL)
        return;

    printf("%d ", parent->data);
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void inorderTraversal(struct TreeNode *parent)
{
    if(parent == NULL)
        return;

    inorderTraversal(parent->left);
    printf("%d ", parent->data);
    inorderTraversal(parent->right);
}

void postorderTraversal(struct TreeNode *parent)
{
    if(parent == NULL)
        return;

    postorderTraversal(parent->left);
    postorderTraversal(parent->right);
    printf("%d ", parent->data);
}

/*==============================================================*/
int main(){
    int test1[10]={0,1,2,3,4,5,6,7,8,9};
    int test2[10]={9,8,7,6,5,4,3,2,1,0};
    int size1 = sizeof(test1)/sizeof(int);
    printf("size 1 is : %d\n", size1);

    int size2 = sizeof(test2)/sizeof(int);
    printf("size 2 is : %d\n", size2);

    struct TreeNode *tree1 = NULL;
    struct TreeNode *tree2 = NULL;

    struct queue *q1 = malloc(sizeof(struct queue));
    q1->front = NULL;
    q1->rear = NULL;
    struct queue *q2 = malloc(sizeof(struct queue));
    q2->front = NULL;
    q2->rear = NULL;

    for(int i=0; i<size1; i++){
        insert(&tree1, &q1, test1[i]);
    }

    for(int i=0; i<size2; i++){
        insert(&tree2, &q2, test2[i]);
    }

    //traverse and print the tree
    printf("Preorder Traversal : ");
    preorderTraversal(tree1);
    printf("\n");

    printf("Inorder Traversal : ");
    inorderTraversal(tree1);
    printf("\n");

    printf("Postorder Traversal : ");
    postorderTraversal(tree1);
    printf("\n");

    //traverse and print the tree
    printf("Preorder Traversal : ");
    preorderTraversal(tree2);
    printf("\n");

    printf("Inorder Traversal : ");
    inorderTraversal(tree2);
    printf("\n");

    printf("Postorder Traversal : ");
    postorderTraversal(tree2);
    printf("\n");

    return 0;
}
/*==============================================================*/