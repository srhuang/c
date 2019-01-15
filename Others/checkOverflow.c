/*****************************************************************
Name    :checkOverflow
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190115 check INT overflow
*****************************************************************/
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*==============================================================*/

/*==============================================================*/

int main(){
    int x=1234567890;
    int a=1000000000;

    printf("INT_MAX:%d\n", INT_MAX);
    printf("INT_MIN:%d\n", INT_MIN);

    //for addition
    //check overflow
    if ((x > 0) && (x > INT_MAX - a))
    {
        printf("x=%d, a=%d, x+a would overflow\n", x, a);
    }

    x=-1234567890;
    a=-1000000000;
    //check underflow
    if ((x < 0) && (x < INT_MIN - a))
    {
        printf("x=%d, a=%d, x+a would underflow\n", x, a);
    }

    //for multiplication
    //check overflow
    x=1234567890;
    a=10;
    if ( (x > INT_MAX / a))
    {
        printf("x=%d, a=%d, x*a would overflow\n", x, a);
    }

    //check underflow
    x=-1234567890;
    a=10;
    if ( (x < INT_MIN / a))
    {
        printf("x=%d, a=%d, x*a would underflow\n", x, a);
    }

    return 0;
}
/*==============================================================*/