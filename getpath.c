#include "shell.h"


char *getpath(char *path)
{
	char *pa;
	char fp[4086];
	char *token;
	char *fol;
	struct stat file;

	pa = _getenv("PATH");
	token = strdup(pa);
	fol = strtok(token, ":");

	while (fol)
	{
		_strcpy(fp, fol);
		_strcat(fp, "/");
		_strcat(fp, path);
		if (stat(fp, &file) == 0)
		{
			free(token);
			path = fp;
			return (path);
		}

		fol = strtok(NULL, ":");
		/*printf("%s %ld\n", fol, _strlen(fol));*/
	}
	free(token);
	free(path);
	return (NULL);
}
