#include "shell.h"


/**
 * getlne - gets line from user and execute command
 * @prompt: prompt to print
 * @program: name of program
 */


void getlne(char *prompt, char *program)
{
	char *linebuff = NULL, *nl = "", **tokens;
	size_t n = 0, i = 0;
	ssize_t chars;
	vo i;

	signal(SIGINT, sig_h);
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		chars = getline(&linebuff, &n, stdin);
		linebuff[chars - 1] = '\0';

		if (chars == 0)
		{
			write(STDOUT_FILENO, nl, 0);
			free(linebuff);
			continue;
		}

		if (chars == -1)
		{
			free(linebuff);
			exit(0);
		}
		if (chars > 1)
		{
			tokens = sep(linebuff);
			if (_strcmp(tokens[0], "exit") == 0)
				free(linebuff);
			if (inbuilts(tokens) == NOT_INBUILT)
			{
				if (execute_bin(tokens) != 0)
				{
					printerr(errno, tokens[0], program);
				}
			}
		}
		if (chars > 1 || chars == -1)
			_free(tokens);
	}
}

/**
 * sig_h - handles ctr-c signal
 * @sig: signal
 */

void sig_h(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);

		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		}
		fflush(stdout);
	}
}
