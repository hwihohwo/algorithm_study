#include <stdio.h>

int	main()
{
	int	input[3];
	int	multi = 1;
	int	arr[10];

	for (int i = 0; i < 3; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < 3; i++)
		multi *= input[i];
	for(int i = 0; i < 10; i++)
		arr[i] = 0;
	while (multi > 0)
	{
		arr[multi % 10]++;
		multi /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return (0);
}