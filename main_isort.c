#include <stdio.h>
#include "isort.h"


#define LENGTHARRAY 50


/**
 * The progrem receives an array and prints it sorted.
*/


int main()
{
    int i;
    int arr[LENGTHARRAY];
    for(i = 0; i<LENGTHARRAY; i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr, LENGTHARRAY);

    for(int i = 0; i < LENGTHARRAY; i++){
        if(i == LENGTHARRAY - 1)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf("%d,", arr[i]);
        }
    }
    printf("\n");
    return 0;
}