#include <stdio.h>

int compare(char* string1, char* string2)
{
    char* p1 = string1;
    char* p2 = string2;
    while (*p1 != '\0' && *p2 != '\0')
    {
        if (*p1 == ' ')
        {
            p1++;
        }

        if (*p2 == ' ')
        {
            p2++;
        }

        if (*p1 != *p2)
        {
            return 0;
        }
        p1++;
        p2++;
    }

    if (*p1 == '\0' && *p2 == '\0') {
        return 1;
    }
}

int main()
{
    char string1[10];
    char string2[10];
    printf("type first string: ");
    fgets(string1, sizeof(string1), stdin);
    printf("type second string: ");
    fgets(string2, sizeof(string2), stdin);
    if (compare(string1, string2))
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }

    return 0;
}