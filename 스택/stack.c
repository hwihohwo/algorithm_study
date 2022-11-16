#include <stdio.h>

#define MX 1000005

int dat[MX];
int pos = 0;

void push(int x)
{
	if (pos == MX)
		return ;
	dat[pos] = x;
	pos++;
}

void pop()
{
	if (pos == 0)
		return ;
	pos--;
}

int top()
{
	if (pos == 0)
	{
		printf("stack is empty\n");
		return (-1);
	}
	return (dat[pos - 1]);
}

int test()
{
  push(5); push(4); push(3);
  printf("%d\n", top()); // 3
  pop(); pop();
  printf("%d\n", top()); // 5
  push(10); push(12);
  printf("%d\n", top()); // 12
  pop();
  printf("%d\n", top()); // 10
}

int	main()
{
	test();
}