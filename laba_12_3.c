//Функция принимает блоки данных {число1,число2, указатель на начало строки}.
//Склеить строку из символов, стоящих в каждой строке в позициях с число1 по число2.
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int len(char *s);
char* conc(int n, ...);

int main()
{
	char *str_1, *str_2, *str_3, *str_4, *str_5;

	printf("%s", conc(4, 0, 2, str_1, 0, 3, str_2, 0, 4, str_3, 0, 5, str_4));

	return 0;
}

int len(char *s)
{
	int i = 0;
	while (s[i] != '\0') i++;
	return i;
}

char* conc(int n, ...)
{
	int i, j,
		*a, *b,
		size = 0;

	char *str,
		 *itog_str;

	itog_str = (char*)calloc(1, 1);

	a = &n + 1;
	b = &n + 2;
	str = (char*)(&n + 3);

	i = 0;
	for (;n;n--)
	{
		str = (char*)calloc(1000, sizeof(char));
		gets(str);
		str = (char*)realloc(str, len(str) * sizeof(char));
		
		size += (*b - *a + 1);
		itog_str = (char*)realloc(itog_str, size * sizeof(char));

		for (j = *a; j <= *b; j++)
		{
			itog_str[i] = str[j];
			i++;
		}

		free(str);

		a += 3;
		b += 3;
		str += 3;
	}

	return itog_str;
}