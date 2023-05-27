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
	char **argv = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "Shell$ ", 7);

		n_read = _getline(&temp, &bytes, STDIN_FILENO);

		if (n_read == -1)
		{
			break;
		}

		argv = parse_token(temp, &ntokens);

		if (strcmp(argv[0], "exit") == 0)
		{
			if (argv[1] == NULL)
			{
				exit(0);
			}
			else
			{
				write(1, "exit: Too many arguments\n", 25);
			}
		}

		executeprogram(argv);

		free(argv);

	}

	free(temp);

}
