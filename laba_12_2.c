// Функция принимает символы. Объединить символы в строки так,
// чтобы в каждой строке получилось одно слово.
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void words(int n, ...);

int main()
{
	words(7, 'a', 'n', ' ', 'd', 'd', 'x', 'm');

	return 0;
}

void words(int n, ...)
{
	char c, *str;
	str = calloc(100, sizeof(char));
	va_list	p;
	va_start(p, n);
	c = va_arg(p, int);
	for (int t = 0; n; n--)
	{
		if (c == ' ')
		{
			printf("%s\n", str);
			t = 0;
		}
		else
		{
			str[t] = c;
			t++;
		}
		c = va_arg(p, int);
	}
	printf("%s", str);
	va_end(p);
}