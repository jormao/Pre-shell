#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int words_in_string(char *str, char *delim);
char **split_string(char *str, char *delim);
#endif /* _MY_SHELL */
