#include "main.h"

char **parse_token(char *temp, int *ntokens)
{
        char *token;
        char *delim = " \n";
        char *temp_copy;
        char **argv = NULL;
        int i = 0;

        *ntokens = 0;

        temp_copy = strdup(temp);

        token = strtok(temp_copy, delim);

        while (token)
        {
                token = strtok(NULL, delim);
                (*ntokens)++;
        }

        argv = malloc(sizeof(char *) * (*ntokens + 1));

        token = strtok(temp, delim);

        while (token)
        {
                argv[i] = token;
                token = strtok(NULL, delim);
                i++;
        }
        argv[i] = NULL;

        free(temp_copy);

        return (argv);
}
