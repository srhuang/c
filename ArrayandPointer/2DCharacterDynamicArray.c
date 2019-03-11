/*****************************************************************
Name    :2DCharacterDynamicArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190302 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
void printArray(char** input)
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%c", input[i][j]);
        }
        printf("\n");
    }
}

/*==============================================================*/
int main(){
    char *test[9]={
        "53..7....", 
        "6..195...", 
        ".98....6.", 
        "8...6...3", 
        "4..8.3..1", 
        "7...2...6", 
        ".6....28.", 
        "...419..5", 
        "....8..79"};

    printArray(test);

    return 0;
}
/*==============================================================*/