/*****************************************************************
Name    :2DintegerArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190117 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/
int **memo;
void twoDimensionalIntegerArray(int x, int y){
    memo = (int**)malloc(sizeof(int*) * x);
    for(int i=0; i<x; i++){
        memo[i] = (int*) malloc (sizeof(int) * y);
    }
}

/*==============================================================*/
int main(){
    int x=10;
    int y=20;

    twoDimensionalIntegerArray(x, y);

    //assign value
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            memo[i][j]=i*y+j;
        }
    }

    //print all values
    int **i=memo;
    int x_count=0;
    while(i <= &memo[x-1]){
        printf("X count : %d\n", x_count);
        int *j=*i;
        int *head=*i;
        int y_count=0;
        while(j <= &head[y-1]){
            printf("\tY count : %d value=%d\n", y_count, *j);
            y_count++;
            j++;
        }
        x_count++;
        i++;
    }

    return 0;
}
/*==============================================================*/
