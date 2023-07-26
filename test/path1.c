#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *env, *tok, *tok1;

	env = getenv("PATH");
	tok = strtok(env, "=");

	tok1 = strtok(tok, ":");
	while (tok1 != NULL)
	{
		printf("%s\n", tok1);
		tok1 = strtok(NULL, ":");
	}
	return (0);
}
