/*****************************************************************
Name    :2DcharArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190122 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/

/*==============================================================*/
int main(){
    //without pointer
    printf("Test without pointer\n");
    char test_data[3][10] = {"aaa", "bbbb", "ccccc"};
    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            printf("test_data[%d][%d] : %c\n", i, j, test_data[i][j]);
        }
    }
    printf("\n");

    //using array of pointer
    printf("Test array of pointer\n");
    char *test_data2[3] = {"aaa", "bbbb", "ccccc"};
    for(int i=0; i<3; i++){
        printf("test_data2[%d] : %s\n", i, test_data2[i]);
    }
    printf("\n");

    //using pointer of pointer
    char **test_data3 = (char**)malloc(sizeof(char*) * 3);
    char **head = test_data3;
    *test_data3 = "aaa";
    test_data3++;
    *test_data3 = "bbbb";
    test_data3++;
    *test_data3 = "ccccc";
    
    for(int i=0; i<3; i++){
        printf("test_data3 : %s\n", *head);
        head++;
    }

    return 0;
}
/*==============================================================*/
