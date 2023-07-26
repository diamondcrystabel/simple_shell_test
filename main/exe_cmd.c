#include "shell.h"

/**
 * execute_cmd - executes commands
 * @tokens: array of arguments
 * @path: full path to command
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
		exit(0);
	}
	if (child > 0)
	{
		wait(&stat);
	}
	if (child == -1)
	{
		perror("execve");
		exit(1);
	}

}
