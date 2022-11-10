#include <stdio.h>
#include <string.h>

#define abs(A) A > 0 ? A : A * (-1)

int	main()
{
	char str1[1000];
	char str2[1000];
	int alpha[26];
	int	result = 0;

	for (int i = 0; i < 26; i++)
		alpha[i] = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	// str1에서는 더하고 str2에서는 빼서 겹치는 알파벳부분은 0으로 만듦.
	for (int i = 0; i < strlen(str1); i++)
		alpha[str1[i] -'a']++;
	for (int i = 0; i < strlen(str2); i++)
		alpha[str2[i] -'a']--;
	for (int i = 0; i < 26; i++)
		result += (abs(alpha[i]));
	printf("%d", result);
}