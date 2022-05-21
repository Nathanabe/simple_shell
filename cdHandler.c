#include "main.h"

/**
 *updateEnv - prepares arguments for the setenvHandler and calls it
 *@key: env key to update
 *@value: value of env
 *@cmds: commands to be passed to setenvHandler
 *@lst_ret: last return value to be passed to setenvHandler
 *Return: void
 */
void updateEnv(char *key, char *value, char **cmds, int *lst_ret)
{
	char **setenv_args;

	setenv_args = malloc(100);
	setenv_args[0] = NULL;
	setenv_args[1] = key;
	setenv_args[2] = value;
	setenv_args[3] = NULL;
	setenvHandler(setenv_args, cmds, lst_ret);
}
/**
 * null_Hyphen - handles null and hyphen arguments
 * @av: arguments
 * @buf: buffer for getcwd
 * @len: length for getcwd
 * @cmds: commands
 * @lst_ret: last return value
 * Return: void
 */
void null_Hyphen(char **av, char *buf, size_t len, char **cmds, int *lst_ret)
{
	char *dir, *currentDir;
	int status;

	if (av[1] == NULL)
	{
		currentDir = getcwd(buf, len);
		updateEnv("OLDPWD", currentDir, cmds, lst_ret);
		dir = _getenv("HOME");
		if (chdir(dir) == 0)
		{
			updateEnv("PWD", dir, cmds, lst_ret);
			free(dir);
			free_entire_arr(av);
			status = 0;
			*lst_ret = status;
			free(buf);
			return;
		}
	}
	if (_strcmp(av[1], "-") == 0)
	{
		currentDir = getcwd(buf, len);
		dir = _getenv("OLDPWD");
		if (chdir(dir) == 0)
		{
			updateEnv("PWD", dir, cmds, lst_ret);
			updateEnv("OLDPWD", currentDir, cmds, lst_ret);
			free(dir);
			free(buf);
			free_entire_arr(av);
			status = 0;
			*lst_ret = status;
			return;
		}
	}
}

/**
 *cdHandler - changes the current working directory
 *@av: arguments
 *@cmds: list of commands entered by the user
 *@lst_ret: status of last run command
 *Return: void
 */
void cdHandler(char **av, char __attribute__((unused))**cmds, int *lst_ret)
{
	int status;
	size_t len = 1000;
	char *currentDir, *buf;

	if (*lst_ret != 0)
	{
		return;
	}
	buf = malloc(1000);
	if (av[1] == NULL || _strcmp(av[1], "-") == 0)
	{
		null_Hyphen(av, buf, len, cmds, lst_ret);
		return;
	}
	currentDir = getcwd(buf, len);
	updateEnv("OLDPWD", currentDir, cmds, lst_ret);
	if (chdir(av[1]) == 0)
	{
		currentDir = getcwd(buf, len);
		updateEnv("PWD", currentDir, cmds, lst_ret);
		free_entire_arr(av);
		status = 0;
		*lst_ret = status;
		free(buf);
		return;
	}
	else
	{
		free(buf);
		perror("Error");
	}
	free_entire_arr(av);
}
