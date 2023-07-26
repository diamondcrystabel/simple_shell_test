#include "main.h"

/**
 * main - copies from one file to another
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0
 */
int main(int ac, char *av[])
{
	int fd1, fd2, r, cw, cr;
	char *buff = malloc(sizeof(char) * 1024);

	if (!buff)
		return (0);
	if (ac != 3)
	{
		dprintf(STDOUT_FILENO,
		"Usage: cp file_from file_tosage: cp file_from file_to\n");
		exit(97);
	} fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd1 < 0)
	{
		dprintf(STDOUT_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	} while ((r = read(fd1, buff, 1024)) > 0)
	{
		if ((write(fd2, buff, r) != r) || fd2 < 0)
		{
			dprintf(STDOUT_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}
	if (r < 0)
	{
		dprintf(STDOUT_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	} cr = close(fd1);
	if (cr < 0)
	{
		dprintf(STDOUT_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	} cw = close(fd2);
	if (cw < 0)
	{
		dprintf(STDOUT_FILENO, "Error: Can't close %d\n", fd2);
		exit(100);
	} free(buff);
	return (0);
}
