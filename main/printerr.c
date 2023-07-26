#include "shell.h"

/**
 * printerr - prints error message
 * @err: err number
 * @cmd: command inputted
 * @prog: program name
 */

void printerr(int err, char *cmd, char *prog)
{
	char *msg, *msg1;

	vo err;
	vo cmd;
	vo prog;
	vo msg;

	if (errno == 123)
	{
		msg = ": 1: ";
		msg1 = ": not found\n";
		write(STDOUT_FILENO, prog, _strlen(prog));
		write(STDOUT_FILENO, msg, _strlen(msg));
		write(STDOUT_FILENO, cmd, _strlen(cmd));
		write(STDOUT_FILENO, msg1, _strlen(msg1));
	}
	else if (errno == 120)
	{
		msg = ": 1: ";
		msg1 = " Permission denied\n";
		write(STDOUT_FILENO, prog, _strlen(prog));
		write(STDOUT_FILENO, msg, _strlen(msg));
		write(STDOUT_FILENO, cmd, _strlen(cmd));
		write(STDOUT_FILENO, msg1, _strlen(msg1));
	}
}
