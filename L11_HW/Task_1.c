#include <stdio.h>


int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int sum(int a, int b)
{
	return a + b;
}

int subtraction(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b)
{
	return a * b;
}

int degree(int a, int b)
{
	if (b != 0)
		return a / b;
	else
		return 0;
}

int main()
{
	int a;
	int b;
	int choose;
	printf("Choose function: \n0 - min\n1 - max\n2 - sum\n3 - subtraction\n4 - multiplication\n5 - degree\n");
	scanf("%d", &choose);
	int (*functions[6])(int, int) = { min, max, sum, subtraction, multiplication, degree };
	int lenth = sizeof(functions) / sizeof(functions[0]);
	printf("Type your values: \n");
	scanf("%d %d", &a, &b);
	printf("Result: %d\n", functions[choose](a, b));
	return 0;
}