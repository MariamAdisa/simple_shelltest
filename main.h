#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

void my_shell();
char **parse_token(char *temp, int *ntokens);
void executeprogram(char **argv);
char *_getenv(const char *name);

#endif
