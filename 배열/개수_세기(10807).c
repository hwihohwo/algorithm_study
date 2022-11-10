#include <stdio.h>

int	main()
{
	int	n;
	int	i;
	int	v;
	int	arr[100];
	int	res[201];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &v);
	for (i = 0; i < 201; i++)
		res[i] = 0;
	for (i = 0; i < n; i++)
		res[arr[i] + 100]++;
	printf("%d", res[v + 100]);
}