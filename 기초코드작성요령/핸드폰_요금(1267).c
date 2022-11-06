#include <stdio.h>
#include <stdlib.h>

int	youngsik(int *time, int n)
{
	int	charge;

	charge = 0;
	for (int i = 0; i < n; i++)
		charge += (time[i] / 30 + 1) * 10;
	return (charge);
}

int	minsik(int *time, int n)
{
	int	charge;

	charge = 0;
	for (int i = 0; i < n; i++)
		charge += (time[i] / 60 + 1) * 15;
	return (charge);
}

int	main()
{
	int	*time;
	int	n;
	int	_youngsik;
	int	_minsik;

	scanf("%d", &n);
	time = (int *)malloc(sizeof(int) * n);
	if (time == NULL)
		exit(1);
	for (int i = 0; i < n; i++)
		scanf("%d ", &time[i]);
	_youngsik = youngsik(time, n);
	_minsik = minsik(time, n);
	if (_youngsik == _minsik)
		printf("%c %c %d", 'Y', 'M', _youngsik);
	else if (_youngsik > _minsik)
		printf("%c %d", 'M', _minsik);
	else
		printf("%c %d", 'Y', _youngsik);
	free(time);
	return (0);
}