#include "my_shell.h"

/**
 * _fork - function to crate parent and child
 * @arr: array with the info for execute
 *
 * Return: always 0
 */

int _fork(char **arr)
{
	int status;
	pid_t pid;

	switch (pid = fork())
	{
		case -1:
			perror("Error");
			exit(-1);
			break;
		case 0:
			if (execve(arr[0], arr, NULL) == -1)
			{
				perror("Error");
				return (0);
			}
			break;
		default:
			do
				waitpid(pid, &status, WUNTRACED);
			while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
			break;
	}
return (0);
}

/**
 * check_in_path - check if the command is found in the path
 * @array_words: array with the command and arguments
 * @e_path: path
 *
 * Return: On success return 1 else return 0
 */

int check_in_path(char **array_words, char *e_path)
{
	int flag, len_tok, tok_index, command_array;
	char **concat_words;
	struct stat find_command;

	flag = 0;
	concat_words = split_string(e_path, ":");
	command_array = _strlen (array_words[0]);
	while (concat_words[tok_index])
	{
		len_tok = _strlen(concat_words[tok_index] + 2);
		concat_words[tok_index] = realloc(concat_words[tok_index], sizeof(char) * (len_tok + command_array));
		_strcat(concat_words[tok_index], "/");
		_strcat(concat_words[tok_index], array_words[0]);
		if (stat(concat_words[tok_index], &find_command) == 0)
		{
			array_words[0] = realloc(array_words[0], sizeof(char) * (len_tok + command_array));
			_strcpy(array_words[0], concat_words[tok_index]);
			flag = 1;
			break;
		}
		tok_index++;
	}
	free_function(concat_words);
	return (flag);
}
