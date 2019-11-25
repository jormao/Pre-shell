#include "my_shell.h"

/**
 * main - evaluate if there is a input and proccess an output
 * @argc: don't used
 * @argv: arguments to proccess
 * @envp: array whit enviroment
 *
 * Return: always 0
 */

int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL, **array_words, *e_path = NULL, *exit_cm, *new_env;
	size_t buffer_size = 0;
	ssize_t prints = 1;
	int flag = 0;
	struct stat find_command;

	(void)argc;
	(void)argv;

	e_path = found_path(envp);
	exit_cm = "exit";
	new_env = "env";

	while (prints > 0)
	{
		signal(SIGINT, sig_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		prints = getline(&buffer, &buffer_size, stdin);
		if (prints == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (prints > 1)
		{
			array_words = split_string(buffer, " ");
			if (!(_strcmp(array_words[0], exit_cm)))
			{
				free_function(array_words);
				exit(0);
			}
			else if (array_words[0] == NULL)
				perror("./hsh");
			else if (!(_strcmp(array_words[0], new_env)))
				print_env(envp);
			else if (stat(array_words[0], &find_command) == 0)
				flag = 1;
			else
				flag = check_in_path(array_words, e_path);
			if (flag == 1)
				_fork(array_words);
			else
				perror("./hsh");
			free_function(array_words);
		}
		flag = 0;
	}
	free(buffer);
	return (0);
}
