#include <stdio.h>

int main()
{
    int a;
    printf("Enter your number:");
    scanf("%d", &a);
    int b;
    a = a * a;
    b = a * a;
    a = a * b;
    a = a * b;
    printf("%d\n", a);

}