/* С клавиатуры вводится номер месяца. Необходимо проверить валидное ли
введенное значение или нет, если нет выдать оператору сообщение об ошибке.
Если значение валидное, вывести на экран название сезона к которому относится месяц */

#include <stdio.h>

int main()
{
    printf("Hello, type your month number:");
    int month;
    scanf("%d", &month);
    if (month >= 1 & month <= 12)
    {
        switch (month)
        {
        case 1:
            printf("Winter\n");
            break;
        case 2:
            printf("Winter\n");
            break;
        case 3:
            printf("Winter\n");
            break;
        case 4:
            printf("Spring\n");
            break;
        case 5:
            printf("Spring\n");
            break;
        case 6:
            printf("Spring\n");
            break;
        case 7:
            printf("Summer\n");
            break;
        case 8:
            printf("Summer\n");
            break;
        case 9:
            printf("Summer\n");
            break;
        case 10:
            printf("Autumn\n");
            break;
        case 11:
            printf("Autumn\n");
            break;
        case 12:
            printf("Autumn\n");
            break;
        }
    }
    else
        printf("Invalid number");

    return 0;
}