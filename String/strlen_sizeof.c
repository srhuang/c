/*****************************************************************
Name    :strlen_sizeof
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190109 Initialization
*****************************************************************/
#include <stdio.h>
#include <string.h>

/*==============================================================*/

void testCharacter(void)
{
    char *test1 = "abcdef";
    char *test2 = "abc\0def";
    char test3[5] = "hijk";
    char test4[] = "0123456789";
    char *test5 = "0123456789";
    
    printf("===testCharacter===\n");
    //strlen for runtime to find end of string
    printf("test1 strlen : %zu\n", strlen(test1));
    printf("test2 strlen : %zu\n", strlen(test2));
    printf("test3 strlen : %zu\n", strlen(test3));
    printf("test4 strlen : %zu\n", strlen(test4));
    printf("test5 strlen : %zu\n", strlen(test5));

    //sizeof for compile time to determine the size of string
    printf("test1 sizeof : %zu\n", sizeof(test1)); // size of poiner
    printf("test2 sizeof : %zu\n", sizeof(test2)); // size of array
    printf("test3 sizeof : %zu\n", sizeof(test3)); // size of pointer
    printf("test4 sizeof : %zu\n", sizeof(test4)); // including \0
    printf("test5 sizeof : %zu\n", sizeof(test5)); // size of pointer
    printf("===testCharacter===\n");
}

void testInteger(void)
{
    int test1[]={0,1,2,3,4,5,6,7,8,9};
    int test2[50]={0,1,2,3,4,5,6,7,8,9};
    int *test3={0,1,2,3,4,5,6,7,8,9};

    printf("===testInteger===\n");
    printf("test1 sizeof : %zu\n", sizeof(test1)); // size of int array * size of int
    printf("test2 sizeof : %zu\n", sizeof(test2)); // size of array * a size of int
    printf("test1 sizeof / sizeof int : %zu\n", sizeof(test1)/sizeof(int)); // size of int array * size of int
    printf("test2 sizeof / sizeof [0] : %zu\n", sizeof(test2)/sizeof(test2[0])); // size of array * a size of int
    printf("test3 sizeof : %zu\n", sizeof(test3)); // size of pointer

    printf("===testInteger===\n");

}

/*==============================================================*/

int main(){
    testCharacter();
    testInteger();

    return 0;
}
/*==============================================================*/