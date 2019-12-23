#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int len(char *s)
{
	int i;
	while (s[i] != '\0') i++;
	return i;
}

void rec(char *s, int i)
{
	// s[i + 1] потому что иначе при выходе из рекурсии выводится ещё и '\0'
	if (s[i + 1] != '\0') rec(s, i + 1);
	printf("%c", s[i]);
}

int main()
{

	char *str;
	str = (char*)malloc(1000 * sizeof(char));
	gets(str);
	str = (char*)realloc(str, len(str) * sizeof(char));

	rec(str, 0);

	getch();
	return 0;
}