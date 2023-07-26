#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i, stat;

	for (i = 0; i < 5; i++)
	{
		if (fork() != 0)
		{
			wait(&stat);
		}
		if (execve(argv[0], argv, NULL) == -1)
		{
			exit(EXIT_FAILURE);
			printf("Error");
		}
	}
}
