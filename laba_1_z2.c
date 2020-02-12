// Структура содержит информацию о фильмах:
// длительность в минутах
// название (указатель)
// вложенную структуру – жанр (строка фиксированной длины)
// год выпуска
// Найти фильмы с заданным названием. Удалить фильмы с длительностью больше заданной.
// сделать функцию ввода и вывода первых двух 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name_genre[13];
}
zochem_janru_structura;

typedef struct
{
	int time;
	char title[13];
	zochem_janru_structura genre;
	int year;
}
film;

void list_commands(int p);
int command_processing();

int main()
{
	film *films;
	int n = 1;
	films = malloc(n * sizeof(film));
	
	list_commands(1);
	while (command_processing(&n, films));
	
	free(films);
	return 0;
}

void list_commands(int p)
{
	if (p)
	{
		printf("Enter \"exit\" to exit.\n");
		printf("Enter \"add\" to add.\n");
		printf("Enter \"find\" to find.\n");
	}
}

int check(char *s)
{
	char commands[3][10] = {"exit", "add", "find"};

	if (strcmp(s, commands[0]) == 0) return 1;
	if (strcmp(s, commands[1]) == 0) return 2;
	if (strcmp(s, commands[2]) == 0) return 3;
	return 0;
}

void add_film(int *n, film *films)
{
	films = realloc(films, *n * sizeof(film));
	printf("Duration of the film (in minutes): ");
	scanf("%d", &films[*n - 1].time);
	
	printf("Name of film: ");
	scanf("%s", films[*n - 1].title);
	
	printf("Film genre: ");
	scanf("%s", films[*n - 1].genre.name_genre);
	
	printf("Year of manufacture: ");
	scanf("%d", &films[*n - 1].year);
	
	*n = *n + 1;
}

void find_film(int *n, film *films)
{
	char name[13];
	
	printf("Enter the name of the movie: ");
	gets(name);
	
	int j;
	for (int i = 0; i < *n; i++)
	{
		if (name[0] == films[i].title[0])
			for (j = 1; name[j]; j++) if (name[j] != films.title[j]) break;
		if (name[j] == 0)
		{
			int pos = j;
			break;
		}
	}
	if (i == *n)
		printf("\nNot found.\n")
	else
	{
		printf("Found!\n");
		printf("Enter \"view\" to view or change the title and duration of a movie.\n")
		printf("Enter \"\"")
	}

}

int command_processing(int *n, film *films)
{
	printf("\nCurrently there are %d movies in the database.\n", *n - 1);

	char command[10] = "";
	int fl = 0;
	do
	{
		fflush(stdin);
		gets(command);
		switch (check(command))
		{
			case 1: return 0; // команда exit
			case 2: add_film(n, films); break;
			case 3: find_film(n, films); break;
			case 0:
			{
				printf("Incorrect! Please repeat input.\n");
				fl = 1;
			};
		}
	}
	while (fl);
	
	return 1;
}