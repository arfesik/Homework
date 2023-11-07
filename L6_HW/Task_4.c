#include <stdio.h>

int main()
{
    int n;
    int result = 8;
    printf("Enter your number: ");
    scanf("%d", &n);
    for (int x = 9; x <= n; ++x)
    {
        result *= x;
    }
    printf("res = %d\n", result);
    return 0;
}