#include "main.h"

/**
 * exec - executes a command
 * @argv: the command's argument vector
 * @last_return: the exit code of the last process
 *
 * Return: void
 */
void exec(char **argv, int *last_return)
{
	char *temp;

	if (isOpr(argv[0]))
	{
		if (_strcmp(argv[0], "||") == 0)
		{
			if (*last_return != 0)
				*last_return = 0;
			else
				*last_return = 1;
		}
		if (_strcmp(argv[0], ";") == 0)
			*last_return = 0;
		if (_strcmp(argv[0], " #") == 0)
			*last_return = 99;
		free_entire_arr(argv);
		exit(*last_return);
	}
	if (*last_return != 0)
	{
		*last_return = 0;
		free_entire_arr(argv);
		exit(*last_return);
	}
	temp = fetch_cmd(argv[0]);
	if (execve(temp, argv, environ) == -1)
		perror("Execve Error:");
	if (temp != argv[0])
		free(temp);
	free_entire_arr(argv);
}
