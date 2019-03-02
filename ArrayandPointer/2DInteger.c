/*****************************************************************
Name    :2DInteger
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190301 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/

/*==============================================================*/

/*==============================================================*/
int main(){
    //Assign array
    int array[3][3] ={
        {1,2,3}, 
        {4,5,6}, 
        {7,8,9}
    }; 
    printf("Array Info : \n");
    printf("\tarray         : %p\n", array);
    printf("\tarray[0] addr : %p\n", &array[0]);
    printf("\tarray[0] val  : %p\n", array[0]);
    printf("\tarray[1] addr : %p\n", &array[1]);
    printf("\tarray[1] val  : %p\n", array[1]);
    printf("\tarray[2] addr : %p\n", &array[2]);
    printf("\tarray[2] val  : %p\n", array[2]);

    //Assign pointer of pointer for dynamic array
    int **ptr = malloc(sizeof(int*)*3);
    for(int i=0; i<3; i++){
        ptr[i] = malloc(sizeof(int)*3);
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ptr[i][j] = i*3+j+1;
        }
    }
    printf("pointer of pointer Info : \n");
    printf("\tPOP   addr : %p\n", ptr);
    printf("\tPOP    val : %p\n", ptr[0]);
    printf("\tPOP+1 addr : %p\n", ptr+1);
    printf("\tPOP+1  val : %p\n", ptr[1]);
    printf("\tPOP+2 addr : %p\n", ptr+2);
    printf("\tPOP+2  val : %p\n", ptr[2]);

    printf("Testing POP\n");
    int** test1 = ptr;
    printf("\t&test1[1][1] : %p\n", &test1[1][1]);
    printf("\ttest1[1][1]  : %d\n", test1[1][1]);

    printf("Testing array...\n");
    printf("\t**array : %d\n", **array);

    printf("Testing int* test2 = array[0][0]\n");
    int* test2 = &array[0][0];
    printf("\t*(test2 += 5) : %d\n", *(test2+=5));

    printf("Testing int (*test3)[3] = &array[0]\n");
    int (*test3)[3] = &array[0];
    printf("\ttest3       : %p\n", test3);
    printf("\t(test3+=2)  : %p\n", test3+=2);
    printf("\t(*test3)[2] : %d\n", (*test3)[2]);

    printf("Testing int* test4 = &array[1]\n");
    int* test4 = &array[1];
    printf("\t(test4+=2)  : %p\n", test4+=2);
    printf("\t(*test4)    : %d\n", (*test4));

    printf("Testing int** test5 = array\n");
    int** test5 = array;
    printf("\ttest5      : %p\n", test5);
    printf("\t(test5+=2) : %p\n", test5+=2);
    printf("\t(*test5)   : %d\n", (*test5));
    printf("\ttest5[1]   : %d\n", test5[1]);

    printf("The Right way the parsing array\n");
    printf("We need change into dynamic array\n");
    int** test6 = malloc(sizeof(int*)*3);
    for(int i=0; i<3; i++){
        test6[i] = malloc(sizeof(int)*3);
        for(int j=0; j<3; j++){
            test6[i][j]=array[i][j];
        }
    }
    for(int i=0; i<3; i++){
        printf("[ ");
        for(int j=0; j<3; j++){
            printf("%d ", test6[i][j]);
        }
        printf("]\n");
    }

    printf("Testing int** test6 = array\n");
    printf("Common Error for assignment of each subarray\n");
    int** test7 = array;
    for(int i=0; i<3; i++){
        test7[i] = &array[i];
    }
    printf("\ttest7[0]    : %x\n", test7[0]);
    printf("\ttest7[1]    : %x\n", test7[1]);
    printf("\ttest7[2]    : %x\n", test7[2]);
    printf("\ttest7[0][0] : %x\n", test7[0][0]);
    printf("\ttest7[0][1] : %x\n", test7[0][1]);
    printf("\ttest7[0][2] : %x\n", test7[0][2]);
    printf("\ttest7[1][0] : %x\n", test7[1][0]);
    printf("\ttest7[1][1] : %x\n", test7[1][1]);
    printf("\ttest7[1][2] : %x\n", test7[1][2]);
    printf("\ttest7[1][3] : %x\n", test7[1][3]);
    printf("Checking the same address\n");
    printf("\t&test7[1]   : %p\n", &test7[1]);
    printf("\t&test7[0][2]: %p\n", &test7[0][2]);
    printf("\t&test7[0][2]: %p\n", &test7[0][3]);
    printf("\t&test7[0][2]: %p\n", &test7[1][0]);


    printf("\nThe Keypoint is the way we look at it.\n");

    return 0;
}
/*==============================================================*/