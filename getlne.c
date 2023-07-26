#include "shell.h"

void getlne(char *prompt, char *program)
{
	char *linebuff = NULL, *nl = "", **tokens;
	size_t n = 0, i = 0;
	ssize_t chars;

	vo i;
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		chars = getline(&linebuff, &n, stdin);
		linebuff[chars - 1] = '\0';

		if (chars == 0)
		{
			write(STDOUT_FILENO, nl, 0);
			continue;
		}

		if (chars == -1)
			exit(0);
		if (chars > 1)
		{
			tokens = sep(linebuff);
			if (execute_bin(tokens) != 0)
			{
				printf("getlne\n");
				printerr(errno, tokens[0], program);
			}
		}
		/*while (tokens[i])
			free(tokens[i++]);
		free(tokens);*/
	}
}
