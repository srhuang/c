/*****************************************************************
Name    :2DCharacter
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
    printf("Test static size array\n");
    char test_data[3][20] = {"aaa", "bbbb", "ccccc"};
    printf("\tsizeof test_data : %lu\n", sizeof(test_data));
    printf("\taddress test_data : %p\n", &test_data);
    for(int i=0; i<3; i++){
            printf("\tsizeof test_data[%d] : %lu\n", i, sizeof(test_data[i]));
    }
    for(int i=0; i<3; i++){
            printf("\taddress of test_data[%d] : %p\n", i, &test_data[i]);
    }
    printf("\n");

    //using array of pointer
    printf("Test array of pointer\n");
    char *test_data2[3] = {"aaa", "bbbb", "ccccc"};
    printf("\tsizeof test_data2 : %lu\n", sizeof(test_data2));
    printf("\taddress test_data2 : %p\n", &test_data2);
    for(int i=0; i<3; i++){
        printf("\tsizeof test_data2[%d] : %lu\n", i, sizeof(test_data2[i]));
    }
    for(int i=0; i<3; i++){
            printf("\taddress of test_data2[%d] : %p\n", i, &test_data2[i]);
    }
    printf("\n");

    //using pointer of pointer
    printf("Test pointer of pointer\n");
    char **test_data3 = (char**)malloc(sizeof(char*) * 3);
    char **head = test_data3;
    *test_data3 = "aaa";
    test_data3++;
    *test_data3 = "bbbb";
    test_data3++;
    *test_data3 = "ccccc";

    printf("\tsizeof test_data3 : %lu\n", sizeof(test_data3));
    printf("\taddress test_data3 : %p\n", &test_data3);
    for(int i=0; i<3; i++){
        printf("\tsizeof test_data3[%d] : %lu\n", i, sizeof(*head));
        head++;
    }
    for(int i=0; i<3; i++){
            printf("\taddress of test_data3[%d] : %p\n", i, &test_data3[i]);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/
