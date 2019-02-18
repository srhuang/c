/*****************************************************************
Name    :dynamic_memory
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190121 Initialize
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================================*/

/*==============================================================*/
int main(){
    int size = 10;

    //Test malloc
    int *arr1 = (int*)malloc(sizeof(int) * size);
    arr1[size-1] = 9527;
    printf("Using malloc : ");
    for(int i=0; i<size; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");

    //Test calloc
    int *arr2 = (int*)calloc(size, sizeof(int));
    printf("Using calloc : ");
    for(int i=0; i<size; i++){
        printf("%d ", arr2[i]);
    }
    printf("\n");

    //Testing realloc will copy the content
    for(int i=0; i<size; i++){
        arr2[i]=i*2;
    }
    //Test realloc
    int *arr3 = (int*)realloc(arr2, sizeof(int) * size * 2);
    if(!arr3){ //check the NULL pointer
        arr3 = arr2;
    }
    arr3[size*2-1] = 9527;
    printf("Using realloc : ");
    for(int i=0; i<size*2; i++){
        printf("%d ", arr3[i]);
    }
    printf("\n");

    free(arr1);
    arr1 = NULL;

    free(arr3);

    if(!arr1){
        printf("arr1 is NULL\n");
    }else{
        printf("arr1 is NOT NULL : %d\n", arr1[size-1]);
    }

    if(!arr2){
        printf("arr2 is NULL\n");
    }else{
        printf("arr2 is NOT NULL : %d\n", arr2[size-1]);
    }

    if(!arr3){
        printf("arr3 is NULL\n");
    }else{
        printf("arr3 is NOT NULL : %d\n", arr3[size*2-1]);
    }

    return 0;
}
/*==============================================================*/