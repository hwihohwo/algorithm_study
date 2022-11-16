#include <stdio.h>

int	stack[100000];
int	pos;

void push(int x)
{
	stack[pos++] = x;
}

void pop()
{
	stack[--pos] = 0;
}

int	main()
{
	int	k, x;
	int	sum = 0;

	scanf("%d%*c", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d%*c", &x);
		if (x == 0)
			pop();
		else
			push(x);
	}
	for (int i = 0; i < pos; i++)
		sum += stack[i];
	printf("%d", sum);
	return (0);
}