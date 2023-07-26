#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pd = getpid();
	printf("Child = %d\n", my_pd);
	printf("Parent = %d\n", getppid());
	return (0);
}
