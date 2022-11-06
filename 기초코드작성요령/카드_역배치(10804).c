#include <stdio.h>

int	main()
{
	int	card[21];
	int	temp;
	int	a, b;
	int	idx;

	for (int i = 1; i <= 20; i++)
		card[i] = i;
	for (int i = 0; i < 10; i++)
	{
		idx = 0;
		scanf("%d %d", &a, &b);
		while (a + idx < b - idx)
		{
			temp = card[a + idx];
			card[a + idx] = card[b - idx];
			card[b - idx] = temp;
			idx++;
		}
	}
	for (int i = 1; i <= 20; i++)
		printf("%d ", card[i]);
	return (0);
}