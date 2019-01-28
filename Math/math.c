/*****************************************************************
Name    :math
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190109 MIN and MAX
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*==============================================================*/
#define MIN(a,b) (((a)<(b))?(a):(b)) 
#define MAX(a,b) (((a)>(b))?(a):(b))

/*==============================================================*/

/*==============================================================*/

/*==============================================================*/
int main(){
    printf("hello world\n");

    //MIN/MAX
    printf("Test MIN/MAX\n");
    int a = 5;
    float b = 3.14;
    printf("\ta= %d, b=%f\n", a, b);
    float ab_min = MIN(a, b);
    float ab_max = MAX(a, b);
    printf("\tmin : %f, max: %f\n", ab_min, ab_max);

    //pow
    printf("Test POW\n");
    double answer = pow(2, 6);
    printf("\t2 ^ 6 = %f\n", answer);

    //random
    printf("Test Random\n");
    //0~99
    int random = (rand()%100);
    printf("\trand 0~99 : %d\n", random);

    return 0;
}
/*==============================================================*/