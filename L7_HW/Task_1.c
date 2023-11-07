#include <stdio.h>

int main()
{
    int x = 201;

    while (x % 17 != 0)
    {
        ++x;
    }
    printf("x = %d\n", x);

    return 0;
}