#include "shell.h"

void printerr(int err, char *cmd, char *prog)
{
	char *msg;

	vo err;
	vo cmd;
	vo prog;
	vo msg;
	if (errno == 123)
	{
		msg = "File not found\n";
		write(STDOUT_FILENO, msg, _strlen(msg));
	}
	else if (errno = 120)
	{
		msg = "Permission denied\n";
		write(STDOUT_FILENO, msg, _strlen(msg));
	}
}
