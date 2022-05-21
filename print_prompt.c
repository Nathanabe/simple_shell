#include "main.h"

/**
 * print_prompt - prints a prompt if in interactive mode
 *
 * Return: void
 */
void print_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		_puts("$ ");
}
