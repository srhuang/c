/*****************************************************************
Name    :string_manipulate
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190121 Initialization
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*==============================================================*/
//function
//strcmp
//strcat
//strcpy
//strstr
//strchr
//strtok
//strncpy

/*==============================================================*/
int main(){
    char test[10] = "asdfgh";
    char *test2 = "asdfqqq";
    char test3[100]="www";

    printf("Input test string : %s\n", test);
    printf("Input test2 string : %s\n", test2);
    printf("Input test3 string : %s\n", test3);

    //string compare arg1-arg2
    if(strcmp(test, test2) != 0){
        printf("test and test2 is NOT the same : %d\n", strcmp(test, test2));
    }

    //string append
    char *string_concat = (char*)malloc(strlen(test3) + strlen(test2));
    strcat(string_concat, test2);
    strcat(string_concat, test3);
    printf("string_concat : %s\n", string_concat);

    //string copy
    char *string_copy = (char*)malloc(strlen(test));
    strcpy(string_copy, test);
    printf("string_copy : %s\n", string_copy);

    //string construct
    char *string_sprintf = (char*)malloc(strlen(test3) + strlen(test2) + strlen(test));
    int test4 = 9527;
    sprintf(string_sprintf, "%s%s%s%d", test, test2, test3, test4);
    printf("string_sprintf : %s\n", string_sprintf);

    //string search for first match
    char *test5 = "This is asdfg a simple asdfg string";
    printf("test5 : %s\n", test5);
    char *find = strstr(test5, "dfg");
    printf("Find : %s\n", find);

    //character search for first match
    char *findChar = strchr(test5, 'a');
    printf("Find Char : %s\n", findChar);

    //string token
    char test6[100] = "aaa/bbb/ccc/ddd.eee,fff,ggg";
    printf("test6 : %s\n", test6);
    char *pch = strtok(test6, "/.,");
    while(pch != NULL){
        printf("%s\n", pch);
        pch = strtok(NULL, "/.,");
    }

    //strncpy
    char *test7 = "This is for string copy.";
    printf("test7 : %s\n", test7);
    int copySize = 6;
    char *substring = malloc(sizeof(char) * copySize);
    strncpy(substring, test7+12, copySize);
    printf("substring : %s\n", substring);

    //replace char from string
    printf("Replace char from string\n");
    test[2]='z';
    printf("test : %s\n", test);
    //maight cause segment fault, cause the string is in executable and read-only.
    //test2[2]='z';
    //printf("test2 : %s\n", test2);

    return 0;
}
/*==============================================================*/