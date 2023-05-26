#include "main.h"

/**
 * get_path - gets the location of the command in the PATH
 * @command: the input command to locate
 *
 * Return: full pathname of the command
 */

char *get_path(char *command)
{
	char **path, *temp;
	list_t *directory, *head;
	struct stat buf;

	path = _getenv("PATH");

	if (!path || !(*path))
		return (NULL);

	directory = get_path_directory(*path + 5);
	head = directory;

	while (directory)
	{
		temp = malloc(_strlen(directory->dir) + _strlen(command) + 2);
		if (!temp)
			return (NULL);

		_strcpy(temp, directory->dir);
		_strcat(temp, "/");
		_strcat(temp, command);

		if (stat(temp, &buf) == 0)
		{
			free_list(head);
			return (temp);
		}

		directory = directory->next;
		free(temp);
	}

	free_list(head);

	return (NULL);
}

/**
 * fill_path_directory - Copies path but replaces leading/trailing
 *		         colons (:) with current working directory.
 * @path: list of directories separated by colons
 *
 * Return: copy of path with leading/trailing colons replaced with the
 *         current working directory
 */

char *fill_path_directory(char *path)
{
	int i, len = 0;
	char *path_copy, *pwd;

	pwd = (getenv("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				len += _strlen(pwd) + 1;
			else
				len++;
		}
		else
			len++;
	}
	path_copy = malloc(sizeof(char) * (len + 1));
	if (!path_copy)
		return (NULL);
	path_copy[0] = '\0';
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(path_copy, pwd);
				_strcat(path_copy, ":");
			}
			else if (path[i + 1] == ':' || path[i + 1] == '\0')
			{
				_strcat(path_copy, ":");
				_strcat(path_copy, pwd);
			} else
				_strcat(path_copy, ":");
		}
		else
			_strncat(path_copy, &path[i], 1);
	}
	return (path_copy);
}

/**
 * get_path_directory - Tokenizes a colon-separated list of
 *                directories into a list_t linked list.
 * @path: list of directories separated by colon.
 *
 * Return: A pointer to the initialized linked list.
 */

list_t *get_path_directory(char *path)
{
	int i;
	char **directory, *path_copy;
	list_t *head = NULL;

	path_copy = fill_path_directory(path);
	if (!path_copy)
		return (NULL);

	directory = _strtok(path_copy, ":");
	free(path_copy);
	if (!directory)
		return (NULL);

	for (i = 0; directory[i]; i++)
	{
		if (add_node_end(&head, directory[i]) == NULL)
		{
			free_list(head);
			free(directory);
			return (NULL);
		}
	}

	free(directory);

	return (head);
}

