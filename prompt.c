#include "my_shell.h"

int main(void)
{
	char *buffer = NULL, **array_words;
	size_t buffer_size = 0;
    ssize_t prints = 1;
	int i = 0, words_to_free = 0;
	 

        while (prints > 0)
        {
			write(STDOUT_FILENO, "$ ", 2);
			prints = getline(&buffer, &buffer_size, stdin);
			if (prints == -1)
				break;
			words_to_free = words_in_string(buffer, " ");
			array_words = split_string(buffer, " ");

			printf("Before execve\n");
    		if (execve(array_words[0], array_words, NULL) == -1)
    		{
        	perror("Error:");
    		}
    		printf("After execve\n");
			
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
