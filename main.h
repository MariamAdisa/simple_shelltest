#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

extern char **environ;

/**
 * struct list_t - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_t
 */

typedef struct list_t
{
	char *dir;
	struct list_t *next;
} list_t;

void my_shell(void);
char **parse_token(char *temp, int *ntokens);
void executeprogram(char **argv);
char *get_path(char *command);
list_t *get_path_directory(char *path);
char **_getenv(const char *var);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char **_strtok(char *line, char *delim);
int count_tokens(char *str, char *delim);
int token_len(char *str, char *delim);

#endif
