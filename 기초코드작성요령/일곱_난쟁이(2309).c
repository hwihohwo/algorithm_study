#include <stdio.h>

void	reorder(int height[9])
{
	int	temp;

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8 - j; i++)
		{
			if (height[i] > height[i + 1])
			{
				temp = height[i];
				height[i] = height[i + 1];
				height[i + 1] = temp;
			}
		}
	}
}

void	print(int height[9])
{
	for (int i = 0; i < 9; i++)
		if (height[i] != 0)
			printf("%d\n", height[i]);
}

int	main()
{
	int	height[9];
	int	sum;

	sum = 0;
	for (int i = 0; i < 9; i++)
		scanf("%d", &height[i]);
	for (int i = 0; i < 9; i++)
		sum += height[i];
	for (int j = 0; j < 8; j++)
	{
		for (int i = j + 1; i < 9; i++)
		{
			if (sum - height[j] - height[i] == 100)
			{
				height[j] = 0;
				height[i] = 0;
				reorder(height);
				print(height);
				return (0);
			}
		}
	}
	return (0);
}