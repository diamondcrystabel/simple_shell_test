#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char **arr = malloc(1024 * sizeof(char));
	char *tok;
	char *buff = NULL;
	int a = 0;
	size_t len;
	ssize_t chars;

	printf("$ ");
	chars = getline(&buff, &len, stdin);
	if (chars == -1)
	{
		printf("An error occurred");
		exit(EXIT_FAILURE);
	}

	tok = strtok(buff, " ");

	printf("[");
	while (tok != NULL)
	{
		arr[a] = malloc(strlen(tok) + 1 * sizeof(char));
		strcpy(arr[a], tok);
		printf("%s ", arr[a]);
		a++;
		tok = strtok(NULL, " ");
	}
	printf("]");
	return (0);
}
