#include "my_shell.h"

int main(int argc, char **argv, char** envp)
{
	char *buffer = NULL, **array_words, *env, **concat_words;
	size_t buffer_size = 0;
	ssize_t prints = 1;
	int i = 0, words_to_free = 0, s = 0, command_array = 0, flag = 0, tok_index, len_tok;
	struct stat find_command;

	(void)argc;
	(void)argv;

	while (envp[s])
	{
	if (!strncmp("PATH", envp[s], 4))
		env = envp[s] + 5;
	s++;
	}
       	while (prints > 0)
        {
			write(STDOUT_FILENO, "$ ", 2);
			prints = getline(&buffer, &buffer_size, stdin);
			if (prints == -1)
				break;
			words_to_free = words_in_string(buffer, " ");
			array_words = split_string(buffer, " ");
			if (stat(array_words[0], &find_command) == 0)
			{
				flag = 1;
			}
			else
			{
				concat_words = split_string(env, ":");
				command_array = strlen (array_words[0]);
				tok_index = 0;
				while (concat_words[tok_index])
				{
					len_tok = strlen(concat_words[tok_index] + 2);
					concat_words[tok_index] = realloc(concat_words[tok_index], sizeof(char) * (len_tok + command_array));
					strcat(concat_words[tok_index], "/");
					strcat(concat_words[tok_index], array_words[0]);
					if (stat(concat_words[tok_index], &find_command) == 0)
					{
						array_words[0] = realloc(array_words[0], sizeof(char) * (len_tok + command_array));
						strcpy(array_words[0], concat_words[tok_index]);
						flag = 1;
						break;
					}
					tok_index++;
				}
			}
			if (flag == 1)
				_fork(array_words);
			if (prints > 1)
			{
				write(STDOUT_FILENO, "$ ", 2);
				write(STDOUT_FILENO, buffer, prints);
			}
			for (i = words_to_free; i >= 0; i--)
				free(array_words[i]);
			free(array_words);
        }

	free(buffer);
        return (0);
}


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

