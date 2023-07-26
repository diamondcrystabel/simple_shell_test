#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	pid_t my_pid;
	static int i;
	int stat;
	char *av[] = {"/bin/ls", "-l", "./", NULL};

	printf("Before fork\n");


	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("Child pid: %d\n", getpid());
			execve(av[0], av, NULL);
			exit(0);
		}
		else
		{
			wait(&stat);
			if (pid == -1)
			{
				exit(EXIT_FAILURE);
				printf("Error\n");
			}
			printf("After fork\n");
			my_pid = getpid();
			printf("Parent pid is %d\n", my_pid);
		}
	}

	return (0);
}
