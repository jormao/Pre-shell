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
char *found_path (char **envp);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void print_env(char **envp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int check_in_path(char **array_words, char *e_path);
void free_function(char **double_point);

#endif /* _MY_SHELL */
