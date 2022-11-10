#include <stdio.h>

int	func2(int arr[], int n)
{
	int	chk_arr[101];
	int	i;

	for (i = 0; i < 101; i++)
		chk_arr[i] = 0;
	for (i = 0; i < n; i++)
		chk_arr[arr[i]]++;
	for (i = 0; i < 50; i++)
		if (chk_arr[i] == 1 && chk_arr[100 - i] == 1)
			return (1);
	if (chk_arr[50] == 2)
		return (1);
	return (0);
}

int	main()
{
	int	arr[] = {50, 50};

	printf("%d\n", func2(arr, 2));
}