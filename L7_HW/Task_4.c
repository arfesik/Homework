#include <stdio.h>

#define MIN(a,b) (a < b ? a : b)

int main()
{
	int x = 12;
	int y = 31;

	printf("%d\n", MIN(x, y));
	return 0;
}