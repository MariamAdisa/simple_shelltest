#include "main.h"

/**
 * executeprogram - executes the program
 * @argv: input string
 */

void executeprogram(char **argv)
{
	int status;
	char *command = NULL;

	pid_t my_pid = fork();

	if (my_pid == -1)
	{
		perror("fork error");
		return;
	}

	if (my_pid == 0)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
			exit(1);
		}
	}

	else
	{
		wait(&status);
	}
}
