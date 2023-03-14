#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all argument of a program
 * @ac: args passed
 * @av: array of argument
 *
 * Return: pointer to string
 */

char *argstostr(int ac, char **av)
{
	char *s = NULL;
	int k = 0, i = ac, j = 0, sum = 0, tmp = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	while (ac--)
		sum += (strlen(av[ac]) + 1);

	s = (char *)malloc(sum + 1);
	if (s != NULL)
	{
		while (k < i)
		{
			for (j = 0; av[k][j] != '\0'; j++)
				s[j + tmp] = av[k][j];
			s[tmp + j] = '\n';
			tmp += (j + 1);
			k++;
		}
		s[tmp] = '\0';
	}
	else
	{
		return (NULL);
	}
	return (s);
}
