#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * num_words - counts the number of words
 * @str: the sting
 *
 * Return: number of worda
 */

int num_words(char *str)
{
	int i = 0;
	int words = 0;
	int len = strlen(str);

	while (i <= len)
	{
		if ((str[i] != ' ') && (str[i] != '\0'))
		{
			i++;
		}
		else if (((str[i] == ' ') || (str[i] == '\0')) && (str[i - 1] != ' '))
		{
			words += 1;
			i++;
		}
		else
			i++;
	}
	return (words);
}

/**
 * strtow - splits a sting into words
 * @str: the sting
 *
 * Return: pointer to the words
 */

char **strtow(char *str)
{
	char **split;
	int i = 0, j = 0, tmp = 0, s = 0, words = num_words(str);
	int len;

	if (words == 0)
		return (NULL);

	len = strlen(str);

	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split != NULL)
	{
		for (i = 0; i <= len && words; i++)
		{
			if ((str[i] != ' ') && (str[i] != '\0'))
			{
				s++;
			}
			else if ((str[i] == ' ') || (str[i] == '\0'))
			{
				if (i && (str[i - 1] != ' '))
				{
					split[j] = (char *) malloc(sizeof(char) * s + 1);
					if (split[j] != NULL)
					{
						while (tmp < s)
						{
							split[j][tmp] = str[(i - s) + tmp];
							tmp++;
						}

					}
					else
					{
						while (j-- >= 0)
							free(split[j]);
						free(split);
						return (NULL);
					}
				}
			}
		}
		split[words] = NULL;
		return (split);
	}
	else
		return (NULL);
}
