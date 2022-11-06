#include <stdio.h>

int	main()
{
	int	input[7];
	int	odd_sum;
	int	odd_min;

	odd_sum = 0;
	odd_min = 100;
	for (int i = 0; i < 7; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < 7; i++)
	{
		if (input[i] % 2 == 1)
		{
			odd_sum += input[i];
			if (odd_min > input[i])
				odd_min = input[i];
		}
	}
	if (odd_sum == 0)
	{
		printf("%d", -1);
		return (0);
	}
	else
	{
		printf("%d\n", odd_sum);
		printf("%d", odd_min);
	}
	return (0);
}