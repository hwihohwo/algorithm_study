#include <stdio.h>

int	main()
{
	int	n;
	int	j;

	scanf("%d", &n);
	for (int i = n; i >= 1; i--)
	{
		for (j = 1; j <= n - i; j++)
			putchar(' ');
		for (j = 1; j <= 2 * i - 1; j++)
			putchar('*');
		putchar('\n');
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i - 1; j++)
			putchar(' ');
		for (j = 1; j <= 2 * i + 1; j++)
			putchar('*');
		putchar('\n');
	}
}