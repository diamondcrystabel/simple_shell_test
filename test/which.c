#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int main(int ac, char **av)
{
	char **buff, *envir, str[10000];
	char *tok, *tok1;
	int i = 0;
	struct stat sb;

	buff = (char**)malloc(10 * sizeof(char));
	if (buff == NULL)
	{
		perror("Error");
		exit(1);
	}

	buff = (char*)malloc(1024 * sizeof(char));
	envir = getenv("PATH");
	tok = strtok(envir, "=");
	tok = strtok(NULL, "=");

	tok1 = strtok(tok, ":");
	while (tok1 != NULL)
	{
		strcpy(buff[i], tok1);
		tok1 = strtok(NULL, ":");
		i++;
	}
	str = av[1];
	if (stat(av[1], &sb) == 0)
	{
		printf("av[%d]\n", 1);
		exit(0);
	}
	for (i = 0; i < 10; i++)
	{
		if (stat(strcat(buff[i], "/")) == 0)
			printf("
}
