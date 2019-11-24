#include "my_shell.h"

/**
 * sig_handler - action for SIGINT change
 * @sig: value for SIGINT
 *
 */

void sig_handler (int sig)
{
	if (sig == SIGINT)
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * found_path - function for found the PATH
 * @envp: pointer with the enviroment
 *
 * Return: pointer to PATH
 */

char *found_path(char **envp)
{
	int i;
	char *env;

	while (envp[i])
	{
		if (!strncmp("PATH", envp[i], 4))
			env = envp[i] + 5;
		i++;
	}
	return (env);
}
