#include <stdio.h>

int	main()
{
	int	n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int	j = 0;
		for (; j < n - i; j++)
			putchar(' ');
		for (; j < n; j++)
			putchar('*');
		for (j = 0; j < i - 1; j++)
			putchar('*');
		putchar('\n');

	}
}