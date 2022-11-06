#include <stdio.h>

int	main()
{
	int	score;

	scanf("%d", &score);
	if (score >= 90 && score <= 100)
		printf("%c", 'A');
	else if (score >= 80 && score <= 89)
		printf("%c", 'B');
	else if (score >= 70 && score <= 79)
		printf("%c", 'C');
	else if (score >= 60 && score <= 69)
		printf("%c", 'D');
	else
		printf("%c", 'F');
	return (0);
}