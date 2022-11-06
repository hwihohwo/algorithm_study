#include <stdio.h>

int	main()
{
	int	n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int j = 0;
		for (; j < n - i; j++)
			putchar(' ');
		for (; j < n; j++)
			putchar('*');
		putchar('\n');
	}
}