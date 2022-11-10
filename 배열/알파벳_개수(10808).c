#include <stdio.h>

int	main()
{
	char word[100];
	int alpha[26];
	int	i;

	for (i = 0; i < 100; i++)
		word[i] = '\0';
	for (i = 0; i < 26; i++)
		alpha[i] = 0;
	scanf("%s", word);
	for (i = 0; i < sizeof(word); i++)
		alpha[word[i] - 'a']++;
	for (i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
}