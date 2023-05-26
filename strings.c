#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: 1st string
 * @src: 2nd string
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len = 0;

	while (dest[i++])
		dest_len++;

	for (i = 0; src[i]; i++)
		dest[dest_len++] = src[i];

	return (dest);
}


/**
 * _strncat - concatenates two strings
 * @dest: destination string to be concatenated upon
 * @src: source string to be appended to @dest
 * @n: number of bytes from scr to be appended to dest
 * Return: a pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, dest_len = 0;

	while (dest[i++])
		dest_len++;

	for (i = 0; src[i] && i < n; i++)
		dest[dest_len++] = src[i];

	return (dest);
}

/**
 * _strcpy - copies a string
 * @dest: destination string to be copied into
 * @src: source string
 * Return: Pointer to the resulting string dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - returns length of a string
 * @s: string to be measured
 * Return: Length of the string
 */

int _strlen(const char *s)
{
	int length = 0;

	while (*s++)
		length++;

	return (length);
}


/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *line, char *delim)
{
	char **str;
	int i = 0, tokens, c, letters, d;

	tokens = count_tokens(line, delim);
	if (tokens == 0)
		return (NULL);

	str = malloc(sizeof(char *) * (tokens + 2));
	if (!str)
		return (NULL);

	for (c = 0; c < tokens; c++)
	{
		while (line[i] == *delim)
			i++;

		letters = token_len(line + i, delim);

		str[c] = malloc(sizeof(char) * (letters + 1));
		if (!str[c])
		{
			for (i -= 1; i >= 0; i--)
				free(str[i]);
			free(str);
			return (NULL);
		}

		for (d = 0; d < letters; d++)
		{
			str[c][d] = line[i];
			i++;
		}

		str[c][d] = '\0';
	}
	str[c] = NULL;
	str[c + 1] = NULL;

	return (str);
}
