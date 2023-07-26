#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *lineptr = NULL, *tok;
	size_t n = 0, len;
	int i = 0, stat;

	(void) i;
	(void) tok;
	(void) len;
	char **buff;
	pid_t pid;
	while (1)
	{
		printf("#cisfun$ ");
		buff = (char**)malloc(1 * sizeof(char));
		if (buff == NULL)
		{
			printf("Unable to allocate memory\n");
			exit(1);
		}
		getline(&lineptr, &n, stdin);
		buff[0] = (char*)malloc(1024 * sizeof(char));
		if (buff[0] == NULL)
		{
			printf("Unable to allocate memory for string\n");
			exit(1);
		}
		for (i = 0; lineptr[i] != '\n'; i++);
		lineptr[i] = '\0';
		strcpy(buff[0], lineptr);
		pid = fork();
		if (pid == -1)
		{
			printf("Error for fork");
			exit(1);
		}
		if (pid == 0)
		{
			if (execve(buff[0], buff, NULL) == -1)
			{
				printf("Error\n");
			}
		}
		else
		{
			wait(&stat);
		}
	}
}
