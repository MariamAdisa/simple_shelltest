#include "main.h"

/**
 * executeprogram - executes the program
 * @argv: input string
 */

void executeprogram(char **argv)
{
	int status;
	pid_t my_pid = fork();

	if (my_pid == -1)
	{
		perror("fork error");
		return;
	}

	if (my_pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("execve error");
			exit(1);
		}
	}

	else
	{
		wait(&status);
	}
}
