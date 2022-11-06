#include <stdio.h>

int	main()
{
	int	n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int	j;
		for (j = 0; j < n - i - 1; j++)
			putchar(' ');
		for (; j < n; j++)
			putchar('*');
		for (j = 0; j < i; j++)
			putchar('*');
		putchar('\n');
	}
	for (int i = 1; i <= n - 1; i++)
	{
		int	j;
		for (j = 0; j < i; j++)
			putchar(' ');
		for (; j < n; j++)
			putchar('*');
		for (j = 0; j < n - 1 - i; j++)
			putchar('*');
		putchar('\n');
	}
}