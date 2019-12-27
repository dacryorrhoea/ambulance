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

	getch();
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
		a, b,
		size = 0;

	char *str,
		 *itog_str;

	itog_str = (char*)calloc(1, 1);

	va_list p;
	va_start(p, n);


	i = 0;
	for (;n;n--)
	{
		a = va_arg(p, int);
		b = va_arg(p, int);
		str = va_arg(p, char*);

		str = (char*)calloc(1000, sizeof(char));
		gets(str);
		str = (char*)realloc(str, len(str) * sizeof(char));
		
		size += (b - a + 1);
		itog_str = (char*)realloc(itog_str, size * sizeof(char));

		for (j = a; j <= b; j++)
		{
			itog_str[i] = str[j];
			i++;
		}

		free(str);
	}

	va_end(p);

	return itog_str;
}