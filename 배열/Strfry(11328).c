#include <stdio.h>
#include <string.h>

int	main()
{
	int	n, i , j, flag;
	char arr1[1000];
	char arr2[1000];
	int alpha[26];

	scanf("%d", &n);
	for (j = 0; j < 1000; j++)
			arr1[j] = '\0';
	for (j = 0; j < 1000; j++)
			arr2[j] = '\0';
	for (i = 0; i < n; i++)
	{
		flag = 1;
		for (j = 0; j < 26; j++)
			alpha[j] = 0;
		scanf("%s %s", arr1, arr2);
		for (j = 0; j < strlen(arr1); j++)
			alpha[arr1[j] - 'a']++;
		for (j = 0; j < strlen(arr2); j++)
			alpha[arr2[j] - 'a']--;
		for (j = 0; j < 26; j++)
		{
			if (alpha[j] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			printf("%s\n", "Possible");
		else
			printf("%s\n", "Impossible");
	}
	return (0);
}

//처음에는 알파벳에 해당하는 엘리먼트를 다 더한다음에 2로 나눈게 1이면 false로 했는데,
// 이 경우 aa ss와 같이 서로 다른 문자가 들어올 경우 오류가 발생한다.
// 정답지를 참고하여 처음 string은 더하고 이후에는 빼는 연산을 해서 0이 아닌
// element가 존재하면 false로 교체.
// 두 string의 알파벳 구성이 동일한지 체크하는 것이니까 제로섬이 더 좋다.