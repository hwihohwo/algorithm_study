#include <stdio.h>

int	main()
{
	int	n;
	int	i;
	int	arr[10];

	scanf("%d", &n);
	for (i = 0; i < 10; i++)
		arr[i] = 0;
	while (n > 0)
	{
		arr[n % 10]++;
		n /= 10;
	}
	n = arr[6] + arr[9];
	if (n % 2 == 1)
	{
		arr[6] = n / 2 + 1;
		arr[9] = n / 2 + 1;
	}
	else
	{
		arr[6] = n / 2;
		arr[9] = n / 2;
	}
	n = arr[0];
	for (i = 0; i < 10; i++)
		if (arr[i] > n)
			n = arr[i];
	printf("%d", n);
	return (0);
}
//   for(int i = 0; i < 10; i++){
//     if(i == 6 || i == 9) continue;
//     ans = max(ans, a[i]);
//   }
//(a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
//   ans = max(ans, (a[6]+a[9]+1)/2);
//   cout << ans;