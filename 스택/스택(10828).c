#include <stdio.h>
#include <string.h>

int	stack[10000];
int	pos;

void push(int x)
{
	stack[pos++] = x;
}

int	pop()
{
	int ret;

	if (pos == 0)
		return (-1);
	else
	{
		ret = stack[--pos];
		return (ret);
	}
}

int	size()
{
	return (pos);
}

int empty()
{
	if (pos == 0)
		return (1);
	else
		return (0);
}

int	top()
{
	if (pos == 0)
		return (-1);
	else
		return (stack[pos - 1]);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i = 0;
	
	while (str1[i] || str2[i])
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	main()
{
	int	n, x;
	char order[6];

	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
			order[j] = '\0';
		scanf("%s%*c", order);
		if (ft_strcmp(order, "push") == 0)
		{
			scanf("%d%*c", &x);
			push(x);
		}
		else if (ft_strcmp(order, "pop") == 0)
			printf("%d\n", pop());
		else if (ft_strcmp(order, "size") == 0)
			printf("%d\n", size());
		else if (ft_strcmp(order, "empty") == 0)
			printf("%d\n", empty());
		else if (ft_strcmp(order, "top") == 0)
			printf("%d\n", top());
	}
}