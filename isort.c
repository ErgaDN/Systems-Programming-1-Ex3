#include <stdio.h>
#include "isort.h"


int shift_element(int *arr, int i)
{
    for (int j = i; j > 0; j--)
    {
        *(arr + j + 1) = *(arr + j);
    }

    return 0;
}

int insertion_sort(int *arr, int len)
{
    int  key, j, count;
    for (int i = 1; i < len; i++)
    {
        key = *(arr + i);
        j = i - 1;
        count = 0;
        while (j >= 0 && *(arr + j) > key)
        {
            count++;
            j--;
        }
        shift_element(arr + j, count);
        *(arr + j + 1) = key;
    }
    return 0;
}