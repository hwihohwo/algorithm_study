#include <stdio.h>

int	sum(int input[5])
{
	int	sum;

	sum = 0;
	for (int i = 0; i < 5; i++)
		sum += input[i];
	return (sum);
}

int	main()
{
	int	input[5];
	int	temp;

	for (int i = 0; i < 5; i++)
		scanf("%d", &input[i]);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4 - j; i++)
		{
			if (input[i] > input[i + 1])
			{
				temp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = temp;
			}
		}
	}
	printf("%d\n", sum(input) / 5);
	printf("%d", input[2]);
	return (0);
}