#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int len(char* s);
void shift_right(char *s, int n, int p);
void sort(char* str);

int main()
{
	char* str;

	str = (char*)malloc(100 * sizeof(char));
	gets(str);
	str = realloc(str, len(str) * sizeof(char));

	sort(str);

	for (int i = 0; str[i]; i++) printf("%c", str[i]);

	free(str);
	return 0;
}

int len(char* s)
{
	int i = 0;
	while (s[i]) i++;
	return i;
}

void shift_right(char *s, int n, int p)
{
	for (int i = n; i > p; i--) s[i] = s[i - 1];
}

void sort(char* str)
{
	int i, k, // счётчкики
		n = 0, // позиция слова
		p = 0; // позиция добавления
	char ch; // для хранения перемещаемого символа

	for (i = 0; str[i]; i++)
		if (str[i] == ' ')
		{
			// нахождение слова с минимальным первым символом
			for (int j = i + 1; str[j] != '\0'; j++)
				if (str[j - 1] == ' ' && str[j] < str[n]) 
					n = j;
				else
					if (str[j - 1] == ' ' && str[j] == str[n])
						for (k = 1; str[n + k] != ' '; k++)
							if (str[j + k] != ' ')
								if (str[n + k] > str[j + k])
								{
									n = j;
									break;
								}
							else
							{
								n = j;
								break;
							}

			// если слово находится правее значит переместить его 
			if (n > i)
			{
				// пока не конец слова запоминать символ
				// делать сдвиг и вставлять символ в 
				// освободившуюся позицию
				while (str[n] != ' ' && str[n] != '\0')
				{
					ch = str[n];
					shift_right(str, n, p);
					str[p] = ch;
					p++; n++;
				}

				// добовляется пробел
				shift_right(str, n - 1, p);
				str[p] = ' ';
				p++;

				// i и n приравниваются p т.к. надо исключить
				// слово которое уже отсортировано
				i = n = p;
			}
			// иначе p и n приравниваются i + 1 т.к. слово
			// уже на своём месте и его надо пропустить
			else p = n = i + 1;
		}
}