#include <stdio.h>

int	main()
{
	int	n;
	int	k;
	int	i, j, s, y;
	int	ret = 0;
	int	arr[2][7];

	for (i = 0; i < 2; i++)
		for (j = 0; j < 7; j++)
			arr[i][j] = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &s, &y);
		arr[s][y]++;
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 1; j < 7; j++)
		{
			if (arr[i][j] % k != 0)
				ret += arr[i][j] / k + 1;
			else
				ret += arr[i][j] / k;
		}
	}
	printf("%d", ret);
}