#include "my_shell.h"

/**
 * count_input - counts the words in the string
 * @str: full string
 *
 * Return: numbers of words
 */

int count_input(char *str)
{
	int i;
	int count = 0;
	int state = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == ':')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			count++;
		}
	}
	return (count);
}

/**
  * split_string - Extract tokens from strings
  * @str: string to token
  * @delim: delims to separate words
  *
  * Return: array whit words tokenized
  */

char **split_string(char *str, char *delim)
{
	char **words = NULL, *token, *buffer;
	int i = 0, aux = 0, count_words = 0, j = 0;

	while (str[j])
	{
		if (str[j] == '\n')
			str[j] = '\0';
		j++;
	}

	count_words = count_input(str);
	buffer = malloc(sizeof(char) * (_strlen(str) + 1));
	if (!buffer)
		return (NULL);
	words = malloc(sizeof(char *) * (count_words + 1));
	if (!words)
		return (NULL);
	_strcpy(buffer, str);
	token = strtok(buffer, delim);

	while (token)
	{
		words[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!words[i])
		{
			for (aux = i; aux >= 0; aux--)
				free(words[aux]);
			free(words);
			return (NULL);
		}
		_strcpy(words[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	words[i] = NULL;
	free(buffer);
	return (words);
}

/**
  * index_function - test the array and choose the correct function to use
  * @buffer: string with commands send by console
  * @envp: enviroment
  *
  */

void index_function(char *buffer, char **envp)
{
	int flag = 0;
	char **array_words, *e_path = NULL;
	struct stat find_command;

	e_path = found_path(envp);
	array_words = split_string(buffer, " \t");
	if (!(_strcmp(array_words[0], "exit")))
		flag = exit_function(array_words, buffer);
	else if (array_words[0] == NULL)
		perror("./hsh");
	else if (!(_strcmp(array_words[0], "env")))
		print_env(envp);
	else if (stat(array_words[0], &find_command) == 0)
		flag = 1;
	else
		flag = check_in_path(array_words, e_path);
	if (flag == 1)
		_fork(array_words, envp);
	if (flag == 0)
		perror("./hsh");
	free_function(array_words);
}

/**
 * _atoi - convert string to int
 *@s: string to convert
 *
 * Return: integer converted
 */
int _atoi(char *s)
{
	unsigned int result = 0;
	int i = 0, j = 0, a = 0, negat = 1;

	while (s[i] != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		if (s[j] == '-')
			negat = negat * -1;
		while ((s[j] >= '0') && (s[j] <= '9'))
		{
			result = (result * 10) + (s[j] - '0');
			j++;
			a = 1;
		}
		if (a == 1)
			j = i;
	}
	result = result * negat;
	return (result);
}

/**
 * exit_function - function to use exit in the shell
 * @array_words: string with tokens
 * @buffer: buffer from the getline
 *
 * Return: 2 if the argument of exit is error
 */

int exit_function(char **array_words, char *buffer)
{
	int arg_exit = 0, flag = 0, len_exit = 0;

	if (array_words[1] == NULL || (!_strcmp(array_words[1], "0")))
	{
		free_function(array_words);
		free(buffer);
		exit(0);
	}
	arg_exit = _atoi(array_words[1]);
	if (arg_exit > 0 && arg_exit <= 255)
	{
		free_function(array_words);
		free(buffer);
		exit(arg_exit);
	}
	else
	{
		len_exit = _strlen(array_words[1]);
		write(STDOUT_FILENO, "exit: Illegal number: ", 22);
		write(STDOUT_FILENO, array_words[1], len_exit);
		write(STDOUT_FILENO, "\n", 1);
		flag = 2;
	}
	return (flag);
}
