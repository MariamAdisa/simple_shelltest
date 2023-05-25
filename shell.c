#include "main.h"
/**
 * my_shell - function that runs the shell
 * Return: Always 0
 */

void my_shell(void)
{
	char *temp = NULL;
	size_t bytes = 0;
	ssize_t n_read;
	int ntokens = 0;
	char **argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "Shell$ ", 7);
		
		n_read = getline(&temp, &bytes, stdin);

		if (n_read == -1)
		{
			break;
		}
		
		if (strcmp(temp, "exit\n") == 0)
		{
			exit(0);
		}

		argv = parse_token(temp, &ntokens);
		
		executeprogram(argv);

		free(argv);

	}

	free(temp);

}
