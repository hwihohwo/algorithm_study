#include <stdio.h>

int	main()
{
	int	arr[9];
	int	max;
	int	max_idx;

	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);
	max = arr[0];
	max_idx = 0;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_idx = i;
		}
	}
	printf("%d\n%d", max, max_idx + 1);
	return (0);
}