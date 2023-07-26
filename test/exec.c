#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execution\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		exit(EXIT_FAILURE);
		printf("Error");
	}
	printf("After execution");
	return (0);
}
