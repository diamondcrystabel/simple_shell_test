#include <stdio.h>

int main(int __attribute__ ((unused)) ac, char **av)
{
	int a = 0;

	while (av[a])
	{
		printf("%s\n",av[a]);
		a++;
	}
}
