#include "main.h"
/**
 * _getenv - gets an environment variable
 * @name: The name or key of the environment variable
 *
 * Return: The value of the environment variable
 **/
char *_getenv(const char *name)
{
	char *token;
	int found = 1;
	int currentIndex = 0;
	char *copy_environ;
	char **env_iterator = environ;

	while (*env_iterator != NULL)
	{
		copy_environ = *env_iterator;
		currentIndex = 0;
		token = _strtok(copy_environ, "=", &currentIndex);
		found = _strcmp(token, name);
		free(token);
		if (found == 0)
		{
			copy_environ = *env_iterator;
			token = _strtok(copy_environ, "=", &currentIndex);
			return (token);
		}
	env_iterator++;
	}
	return (NULL);
}
