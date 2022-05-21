#include "main.h"

/**
 * exec_cmds - executes commands from the same line
 * @av: the av of the main function
 * @cmds: the commands
 *
 * Return: void
 */
void exec_cmds(char **av, char **cmds)
{
	char **argv;
	int status, i, last_return = 0;
	pid_t child_pid;

	for (i = 0; cmds[i]; i++)
	{
		if (last_return == 99) /* " #" detected in previous cmd */
			break;
		argv = mkargv(cmds[i]);
		if (argv == NULL)
			continue;
		if (argv[0] == NULL)
		{
			free_entire_arr(argv);
			continue;
		}
		if (isOpr(argv[0]) != 1 && cmd_exists(argv[0]) != 1)
		{
			perror(av[0]);
			free_entire_arr(argv);
			continue;
		}
		if (get_builtin(argv[0]) && last_return == 0)
		{
			exec_builtin(argv[0], argv, cmds, &last_return);
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: unable to fork");
			free_entire_arr(argv);
			continue;
		}
		if (child_pid == 0)
			exec(argv, &last_return);
		else
			parent(&status, argv, &last_return);
	}
}
