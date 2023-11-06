// Напечатать таблицу умножения на 7. В виде : 1 х 7 = 7
// 2 х 7 = 14 :

#include <stdio.h>

    int main()
{
    int a = 1;
    int b = 7;
    for (int i = 1; i <= 10; i++)
    {
        printf("%d", a);
        printf("x");
        printf("%d", b);
        printf("=");
        printf("%d\n", a * b);
        a++;
    }

    return 0;
}