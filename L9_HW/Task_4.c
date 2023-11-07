#include <stdio.h>

int main()
{
	int max = 0;
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}
	printf("index max arr[%d", max);
	printf("]");
	return 0;
}
