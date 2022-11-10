#include <stdio.h>

// 스택 오버플로우가 발생해서 전역 변수로 뺐음.
int	arr[100000];
int	ret[2000000];

int	main()
{
	int	n, x, i, count;

	count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &x);
	for (i = 0; i < 2000000; i++)
		ret[i] = 0;
	for (i = 0; i < n; i++)
		ret[arr[i]]++;
	for (i = 0; i < 500000; i++)
	{
		if (i >= x)
			break;
		if (ret[i] == 1 && ret[x - i] == 1 && x - i != i)
			count++;
	}
	printf("%d", count / 2);
	return (0);
}
// 숫자를 element로 받는배열(ret) 작성시에 1000001로 해야 1000000까지 element로 받을 수 있다.
// x / 2 == arr[i]인 경우가 문제가 발생했음. count되면 안되지만 ret[diff_abs(x, arr[i])] == 1
// 을 만족하므로 에러.
// 기존 방법 ret[diff_abs(x, arr[i])]이 문제가 많아 변경.
// 변경 이후 x값이 매우 클 경우 outofbound가 발생해서 ret배열의 최댓값을 2000000으로 변경.
// 모두 체크후에 count를 2로 나누는 방식을 사용했지만 그냥 반복 자체를 (x+1)/2로 잡아두면 해결.