#include "stdio.h"


int main(void)
{
    int arr1[5][7] = { {1, 2, 3, 4, 5, 6, 7},
                      {8, 9, 10, 11, 12, 13, 14},
                      {15, 16, 17, 18, 19, 20, 21},
                      {22, 23, 24, 25, 26, 27, 28},
                      {29, 30, 31, 32, 33, 34, 35} };

    int arr2[5][7] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            arr2[i][j] = (i * 7) + j;
        }

    }
