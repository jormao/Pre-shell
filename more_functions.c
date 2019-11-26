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
	int i = 0;
	char *env = NULL;

	while (envp[i])
	{
		if (!_strncmp("PATH", envp[i], 4))
			env = envp[i] + 5;
		i++;
	}
	return (env);
}

/**
 * _strcmp - function that that compares two strings
 * @s1: first value to compare
 *@s2: second value to compare
 *
 * Return: 0 if are equal o else return a integer.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0, k, m = 0;

	while (s1[i] != 0)
	{
		i++;
	}
	while (s2[j] != 0)
	{
		j++;
	}
	for (k = 0; k <= i && k <= j; k++)
	{
		if (s1[k] != s2[k])
		{
			m = (s1[k] - '0') - (s2[k] - '0');
			break;
		}
	}
	return (m);
}

/**
 * print_env - function for found the PATH
 * @envp: pointer with the enviroment
 *
 */

void print_env(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * free_function - function to free pointer to pointer
 * @double_point: pointer to pointer
 *
 */

void free_function(char **double_point)
{
	char **tmp = double_point;

	if (!double_point)
		return;
	while (*double_point)
		free(*double_point++);
	free(tmp);
}
