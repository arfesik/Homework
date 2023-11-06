int main()
{
    int a;
    printf("Enter your number:");
    scanf("%d", &a);
    int b;
    b = a * a;
    b = b * a;
    a = b * a;
    printf("%d", a);

}