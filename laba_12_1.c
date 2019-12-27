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
	char *p, *str;
	str = calloc(100, sizeof(char));
	p = (char*)(&n + 1);
	for (int t = 0; n; n--)
	{
		if (*p == ' ')
		{
			printf("%s\n", str);
			t = 0;
		}
		else
		{
			str[t] = *p;
			t++;
		}
		p += 4;
	}
	printf("%s", str);
}