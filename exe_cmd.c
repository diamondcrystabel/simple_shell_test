#include "shell.h"

/**
 * execute_bin - executes commands
 * @tokens: array of arguments
 * @path
 */

void execute_cmd(char **tokens, char *path)
{
	size_t i = 0;
	int stat;
	pid_t child;

	child = fork();

	while (tokens[i])
	{
		i++;
	}
	tokens[i] = NULL;
	if (child == 0)
	{
		execve(path, tokens, environ);
		i = 0;
		/*while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}*/
		/*free(tokens);*/
		exit(0);
	}
	if (child > 0)
	{
		/*while (tokens[i])
			free(tokens[i++]);*/
		wait(&stat);
	}
	if (child == -1)
	{
		perror("execve");
		exit(1);
	}

}
