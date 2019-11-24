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
    char *buffer = NULL, **array_words, *e_path, **concat_words;
    size_t buffer_size = 0;
    ssize_t prints = 1;
    int i = 0, words_to_free = 0, command_array = 0, flag = 0, tok_index, len_tok;
    struct stat find_command;

    (void)argc;
    (void)argv;

	e_path = found_path(envp);
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
			words_to_free = words_in_string(buffer, " ");
			array_words = split_string(buffer, " ;");
			if (stat(array_words[0], &find_command) == 0)
			{
	    		flag = 1;
			}
		else
		{
	    	concat_words = split_string(e_path, ":");
	    	command_array = _strlen (array_words[0]);
	    	tok_index = 0;
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
		}	
		if (flag == 1)
	    	_fork(array_words);
		else
	    	perror("./hsh");
		for (i = words_to_free; i >= 0; i--)
	    	free(array_words[i]);
		free(array_words);
	}
	flag = 0;
    }
	free(buffer);
    return (0);
}
