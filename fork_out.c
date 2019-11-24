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
