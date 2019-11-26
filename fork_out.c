#include "my_shell.h"

/**
 * _fork - function to crate parent and child
 * @arr: array with the info for execute
 * @envp: enviroment
 *
 * Return: always 0
 */

int _fork(char **arr, char **envp)
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
			if (execve(arr[0], arr, envp) == -1)
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
 * @arr_words: array with the command and arguments
 * @e_path: path
 *
 * Return: On success return 1 else return 0
 */

int check_in_path(char **arr_words, char *e_path)
{
	int flag = 0, len_tok, idx = 0, len_arr;
	unsigned int new_size, old_size;
	char **cat_words;
	struct stat find_command;

	flag = 0;
	cat_words = split_string(e_path, ":");
	len_arr = _strlen(arr_words[0]);
	while (cat_words[idx])
	{
		len_tok = _strlen(cat_words[idx]) + 2;
		new_size = (sizeof(char) * (len_tok + len_arr));
		old_size = (_strlen(cat_words[idx]) + 1);
		cat_words[idx] = _realloc(cat_words[idx], old_size, new_size);
		_strcat(cat_words[idx], "/");
		_strcat(cat_words[idx], arr_words[0]);
		if (stat(cat_words[idx], &find_command) == 0)
		{
			arr_words[0] = _realloc(arr_words[0], (len_arr + 1), new_size);
			_strcpy(arr_words[0], cat_words[idx]);
			flag = 1;
			break;
		}
		idx++;
	}
	free_function(cat_words);
	return (flag);
}
