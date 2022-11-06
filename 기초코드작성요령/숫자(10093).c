#include <stdio.h>

int	main()
{
	long long a;
	long long b;
	long long temp;

	scanf("%lld %lld", &a, &b);
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a == b)
		printf("%d\n", 0);
	else	
		printf("%d\n", b - a - 1);
	for (long long i = a + 1; i < b; i++)
		printf("%lld ", i);
	return (0);
}