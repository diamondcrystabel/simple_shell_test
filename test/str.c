#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[2000] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char *tok;

	tok = strtok(str, ":");
	while (tok != NULL)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, ":");
	}
	return (0);
}
