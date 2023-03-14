#include "main.h"
#include <unistd.h>
/**
 * _putchar - wrires the character c to stdout
 * @c: The characterto print
 *
 * Return: on success 1.
 * on error, -1 is returned, and error is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
