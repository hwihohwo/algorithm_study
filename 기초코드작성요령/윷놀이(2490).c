#include <stdio.h>

int	main()
{
	int	a[4];
	int	back_num;

	for (int try = 0; try < 3; try++)
	{
		back_num = 0;
		scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
		for (int i = 0; i < 4; i++)
			if (a[i] == 0)
				back_num++;
		if (back_num == 0)
			printf("%c\n", 'E');
		else if (back_num == 1)
			printf("%c\n", 'A');
		else if (back_num == 2)
			printf("%c\n", 'B');
		else if (back_num == 3)
			printf("%c\n", 'C');
		else if (back_num == 4)
			printf("%c\n", 'D');
	}
		return (0);
}

// 입력이 0과 1로만 주어지니까 입력받은 값을 result에 다 더해줘서 결과를 보면된다.