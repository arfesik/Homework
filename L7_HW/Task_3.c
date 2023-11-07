#include <stdio.h>

int main()
{
    int n = 0;
    printf("¬ведите высоту треугольника: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf(" ");
        }

        for (int j = n - 2 * i; j <= n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}