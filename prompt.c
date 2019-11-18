#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

int main(void)
{
	char *buffer = NULL, **array_words;
	size_t buffer_size = 0;
    ssize_t prints = 1;
	int i = 0;
	 

        while (prints > 0)
        {
			write(STDOUT_FILENO, "$ ", 2);
			prints = getline(&buffer, &buffer_size, stdin);
			array_words = split_string(buffer, " ");

			while (array_words[i])
			{
				printf("SECTION MAIN | Value of prints: %s\n", array_words[i]);
				i++;
			}
			i = 0;
			
			if (prints > 1)
			{
				write(STDOUT_FILENO, "$ ", 2);
				write(STDOUT_FILENO, buffer, prints);
			}
        }
	free(buffer);
	free(array_words);
        return (0);
}
