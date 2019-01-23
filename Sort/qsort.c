/*****************************************************************
Name    :qsort
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190122 Initialize
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/

/*==============================================================*/
int compare(const void *arg1, const void *arg2) {
    return (*(const int *)arg1 - *(const int *)arg2);
}

int swap(int *arry, int *arry2){
    int temp = *arry;
    *arry = *arry2;
    *arry2 = temp;
}

void my_qsort(int *array, int left, int right){
    printf("left=%d, right=%d\n", left, right);
    if(left >= right)
        return;

    //divide
    int pivot = array[(left+right)/2];
    printf("pivot:%d\n", pivot);

    int i=left-1;
    int j=right+1;
    while(i<j){
        do{
            i++;
        }while(array[i]<pivot);

        do{
            j--;
        }while(array[j]>pivot);

        //i,j point to swap element
        if(i<j){
            printf("swap i=%d, j=%d\n", i, j);
            swap(&array[i], &array[j]);
        }
    }

    //conquer
    my_qsort(array, left, i-1);
    my_qsort(array, j+1, right);
}


/*==============================================================*/
int main ()
{
    int values[6] = { 40, 10, 100, 90, 20, 25 };
    int size = sizeof(values)/sizeof(int);
    //qsort (values, size, sizeof(int), compare);
    my_qsort(values, 0, size-1);
    for(int i=0; i<size; i++){
        printf ("%d ",values[i]);
    }
    printf("\n");
    
    return 0;
}
/*==============================================================*/
