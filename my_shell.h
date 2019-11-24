#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int words_in_string(char *str, char *delim);
char **split_string(char *str, char *delim);
int _fork(char **arr);
void sig_handler (int sig);
#endif /* _MY_SHELL */
