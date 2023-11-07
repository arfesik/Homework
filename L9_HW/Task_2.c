#include <stdio.h>

int main()
{
    int arr[10] = { 1,3,2,4,6,5,7,9,8,10 };
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    for (int i = 0; i < 9; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}