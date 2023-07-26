#include "shell.h"

/**
 * _strdup - duplicates a string
 * @s: string to be duplicated
 * Return: s
 */

char *_strdup(char *s)
{
	char *ptr;
	size_t i = 0;

	printf("_strdup");
	ptr = malloc(_strlen(s) + 1 * sizeof(ptr));
	if (ptr == NULL)
	{
		perror("Unable to allocate memory for _strdup");
		exit(94);
	}

	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';

	return (ptr);
}
