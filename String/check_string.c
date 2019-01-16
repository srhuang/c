/*****************************************************************
Name    :check_string
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190116 Initialization
*****************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*==============================================================*/

/*==============================================================*/

int main(){
    char test[100] = "123 dfg 456 ABC_*-^\tC4";
    printf("Test String : %s\n", test);

    char *iterator=test;
    while(*iterator != 0){
        printf("\nStarting Parsing:%c\t", *iterator);
        if(isspace(*iterator)){
            printf("[isspace]");
        }
        if(isdigit(*iterator)){
            printf("[isdigit]");
        }
        if(isalpha(*iterator)){
            printf("[isalpha]");
        }
        if(islower(*iterator)){
            printf("[islower]");
        }
        if(isupper(*iterator)){
            printf("[isupper]");
        }
        if(isalnum(*iterator)){
            printf("[isalnum]");
        }
        if(isxdigit(*iterator)){
            printf("[isxdigit]");
        }
        if(ispunct(*iterator)){
            printf("[ispunct]");
        }
        iterator++;
    }


    return 0;
}
/*==============================================================*/