#include "shell.h"


char *_getenv(char *name)
{
	int i = 0;
	char *tok;

	while (environ[i])
	{
		/*tok = strtok(environ[i], "=");*/
		/*printf("%s and %s\n", tok, name);*/
		char *ptr;
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			ptr = strdup(environ[i]);
			strtok(ptr, "=");
			tok = strtok(NULL, "=");
			return (tok);
		}

		i++;
	}
	return (NULL);
}

int _strcmp(char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}

int _strncmp(char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
		{
			return (-1);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
