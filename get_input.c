#include "main.h"

/**
 * get_input - gets input and turns it into cmds
 * @av: the argument vector of the main function
 *
 * Return: a char pointer of the commands
 */
void get_input(char **av)
{
	char **cmds, *cmd_line, line[BUFSZ] = {0};
	ssize_t nread = 0;
	int currIndex = 0;

	print_prompt();
	nread = _getline(line, BUFSZ);
	if (nread == -1)
		exit(0);	/* EOF (Ctrl+D) captured */
	while ((cmd_line = _strtok(line, "\n", &currIndex)) != NULL)
	{
		cmds = makeCmds(cmd_line);
		if (cmds == NULL)
		{
			perror("Error: failed to create commands");
			get_input(av);
		}
		exec_cmds(av, cmds);
		free_entire_arr(cmds);
		free(cmd_line);
	}
}
