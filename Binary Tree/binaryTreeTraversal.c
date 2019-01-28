/*****************************************************************
Name    :binaryTreeTraversal
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190128 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
typedef struct treeNode
{
    struct treeNode *left;
    struct treeNode *right;
    int data;
}treeNode;

/*==============================================================*/
treeNode * arrayToTree(int *array, int num)
{
    printf("Array to linked list : ");
    printf("%d\t", array[0]);

    treeNode *root = (treeNode*)malloc(sizeof(treeNode));
    root->data=array[0];
    root->left=NULL;
    root->right=NULL;

    treeNode *parent=root;
    for(int i=1; i<num; i++){
        printf("%d\t", array[i]);
        treeNode *current = (treeNode*)malloc(sizeof(treeNode));
        current->data = array[i];
        current->left = NULL;
        current->right = NULL;
        if(parent->left == NULL){
            parent->left=current;
        }else{
            parent->right=current;
            parent = parent->left;
        }
    }
    printf("\n");

    return root;
}

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
    int test[10]={0,1,2,3,4,5,6,7,8,9};

    treeNode *root = arrayToTree(test, sizeof(test)/sizeof(int));

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