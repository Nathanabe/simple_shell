#include "main.h"


/**
 * exec_shell - gets input and turns it into cmds
 * @av: the argument vector of the main function
 *
 * Return: a char pointer of the commands
 */
void exec_shell(char **av)
{
	char **cmds, *cmd_line, line[BUFSZ] = {0};
	ssize_t nread = 0;
	int currIndex = 0, cmd_count;

	print_prompt();
	nread = _getline(line, BUFSZ);
	if (nread == -1)
		exit(0);	/* EOF (Ctrl+D) captured */
	cmd_count = 0;
	while ((cmd_line = _strtok(line, "\n", &currIndex)) != NULL)
	{
		if (_strcmp(cmd_line, "") == 0)
			continue;
		cmds = makeCmds(cmd_line);
		free(cmd_line);
		if (cmds == NULL)
		{
			perror("Error: failed to create commands");
			exec_shell(av);
		}
		if (_strcmp(cmds[0], "exit") == 0 && cmd_count)
		{
			free_entire_arr(cmds);
			exit(2);
		}
		exec_cmds(av, cmds);
		free_entire_arr(cmds);
		cmd_count++;
	}
}
