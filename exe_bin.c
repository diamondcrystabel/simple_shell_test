#include "shell.h"

int execute_bin(char **tokens)
{
	char *com = tokens[0];
	char *path;
	int i = 0;

	/*printf("exe_bin\n");*/
	if (com[0] == '/' || com[0] == '.')
	{
		if (access(com, F_OK) != 0)
		{
			while (tokens[i])
				free(tokens[i++]);
			free(tokens);
			free(com);
			errno = 123;
			return (-1);
		}
		if (access(com, F_OK) != 0 && access(com, X_OK) != 0)
		{
			while (tokens[i])
				free(tokens[i++]);
			free(tokens);
			free(com);
			errno = 120;
			return (-1);
		}
		path = com;
	}
	else
	{
		path = getpath(com);
		if (path == NULL)
		{
			printf("exe_bin\n");
			errno = 123;
			/*while (tokens[i])
				free(tokens[i++]);*/
			return (-1);
		}
	}
	execute_cmd(tokens, path);
	return (0);
}
