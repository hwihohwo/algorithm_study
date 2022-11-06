#include <stdio.h>

int	main()
{
	int	n;
	int	x;
	int	a;
	int	i;

	i = 0;
	scanf("%d %d", &n, &x);
	while (i < n)
	{
		scanf("%d ", &a);
		if (a < x)
			printf("%d ", a);
		i++;
	}
	return (0);
}