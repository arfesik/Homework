#include <stdio.h>

int main() 
{
	for (int x = 1; x < 6; x++) 
	{
		if (x < 5) 
		{
			for (int i = 5; i > x; i--) 
			{
				printf(" ");
			}
		}
		for (int j = x; j > 0; j--) {
			printf(" %d", j);
		}
		printf("\n");
	}
	return 0;
}