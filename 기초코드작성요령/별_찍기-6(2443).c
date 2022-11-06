#include <stdio.h>

int	main()
{
	int	n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int	j;
		for (j = 0; j < i; j++)
			putchar(' ');
		for (; j < n; j++)
			putchar('*');
		for (j = 0; j < n - i - 1; j++)
			putchar('*');
		putchar('\n');
	}
}

//   for(int i = N; i >= 1; i--)
//   {
//     for(int j = 1; j <= N - i; j++)
// 		cout << ' ';
//     for(int j = 1; j <= 2 * i - 1; j++)
// 		cout << '*';
//   }