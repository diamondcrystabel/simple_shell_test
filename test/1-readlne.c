#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t len = 0;
	char *buff = malloc(len * sizeof(char));
	ssize_t characters;

	if (buff == NULL)
	{
		printf("Cannot allocate space");
		exit(EXIT_FAILURE);
	}

	printf("$ ");
	characters = getline(&buff, &len, stdin);
	if (characters < 0)
	{
		printf("Error occurred");
		exit(EXIT_FAILURE);
	}
	printf("%s", buff);
}
