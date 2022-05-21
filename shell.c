#include "main.h"

/**
 * main - a super simple shell
 * @ac: the argument count
 * @av: the argument vector
 *
 * Return: 0 upon success, 1 upon failure
 */
int main(int ac, char **av)
{
	if (av[1] != NULL)
		exec_file(ac, av);
	while (1)
		exec_shell(av);
	return (0);
}
