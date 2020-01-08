#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>

int srednee(int n, ...);
int sum(int n, ...);

int main()
{
	int (*func) (int, ...);
	func = srednee;
    printf("%d\n", func(8, 2, -1, 4, -9, 5, -3, -4, 6));
    func = sum;
    printf("%d\n", sum(4, 3, 4, 5, 8));
    return 0;
}

int sum(int n, ...)
{
	int sum = 0,
		*p;
	p = &n + 1;
	for (; n; n--) sum += *(p++);
	return sum;
}

int srednee(int n, ...)
{
	int *p,
		sum = 0,
		k = 0;

	p = &n + 1;
	for (; n; n--)
	{
		if (*p >= 0)
		{
			sum += *p;
			k++;
		}
		p++;	}
    
	return sum / k;
}