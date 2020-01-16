#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int len(char* s);
int substring(char *s1, char *s2);

int main()
{
	char *str, *sub;

	str = (char*)malloc(100 * sizeof(char));
	gets(str);
	str = realloc(str, len(str) * sizeof(char));

	sub = (char*)malloc(100 * sizeof(char));
	gets(sub);
	sub = realloc(sub, len(sub) * sizeof(char));

	if (substring(str, sub))
		printf("include");
	else
		printf("not include");

	free(str);
	return 0;
}

int len(char* s)
{
	int i = 0;
	while (s[i]) i++;
	return i;
}

int substring(char *s1, char *s2)
{
	int i, n = len(s1) - len(s2) + 1;

	for (; n >= 0; n--)
		if (s1[n] == s2[0])
		{
			for (i = 1; s2[i] != '\0'; i++) if (s1[n + i] != s2[i]) break;
			// если нужен индекс входа подстроки то заменить 1 на n
			if (s2[i] == '\0') return 1; 
		}

	return 0;
}