#include <stdio.h>

int	max(int a, int b, int c)
{
	int	max;

	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return (max);
}

int	main()
{
	int	a;
	int	b;
	int	c;

	scanf("%d %d %d", &a, &b, &c);
	if (a == b && b == c)
		printf("%d", 10000 + a * 1000);
	else if (a == b && b != c)
		printf("%d", 1000 + a * 100);
	else if (a == c && a != b)
		printf("%d", 1000 + a * 100);
	else if (b == c  && b != a)
		printf("%d", 1000 + b * 100);
	else
		printf("%d", max(a, b, c) * 100);
	return (0);
}

// if, else if 로 걸러지는 조건들은 다음 else if 에서 굳이 추가할 필요가 없지.
// 3가지 숫자를 배열로 받아서 정렬한뒤에 처음과 끝이 같으면 모두 동일, 2개만 같으면 2개, 
// 그리고 else로 해결도 가능.