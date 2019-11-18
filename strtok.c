#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char *buffer = stdin;
	char delim[ ] = ",-.";
	char *token;
	size_t i = 0;

	token = strtok(buffer, delim);

	while (token != NULL)
	{
		while (token[i])
			i++;
		write(STDOUT_FILENO, buffer, i);
		token = strtok(NULL, delim);
		i = 0;
	}
	return (0);
}
