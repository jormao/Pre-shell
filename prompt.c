#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *buffer;
	size_t buffer_size = 20;
        ssize_t prints = 1;

	buffer = (char *)malloc(buffer_size * sizeof(char));
	if( buffer == NULL)
	{
		perror("error doing malloc\n");
		exit(98);
	}
        while (prints > 0)
        {
		write(STDOUT_FILENO, "$ ", 2);
		prints = getline(&buffer, &buffer_size, stdin);
		if (prints > 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
			write(STDOUT_FILENO, buffer, prints);
		}
        }
	free(buffer);
        return (0);
}

/**
 * 
