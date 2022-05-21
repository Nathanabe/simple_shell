#include "main.h"

/**
 * exitHandler - handles the exit built-in
 * @argv: the arument vector of the current command
 * @cmds: the commands
 * @last_return: the exit code of the last command
 *
 * Return: void
 */
void exitHandler(char **argv, char **cmds, int *last_return)
{
	int status;
	char err[BUFSZ] = {0};

	if (*last_return != 0)
		return;
	if (argv[1] == NULL)
	{
		free_entire_arr(argv);
		free_entire_arr(cmds);
		exit(0);
	}
	if (is_number(argv[1]))
	{
		status = _atoi(argv[1]);
		free_entire_arr(argv);
		free_entire_arr(cmds);
		exit(status);
	}
	_strcat(err, "./hsh: 1: exit: Illegal number: ");
	_strcat(err, argv[1]);
	_strcat(err, "\n");
	write(STDERR_FILENO, err, _strlen(err));
	exit(2);
}
