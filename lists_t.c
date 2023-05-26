#include "main.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to head of the list
 * @dir: input string
 *
 * Return: address of new node or NULL if it fails
 */

list_t *add_node_end(list_t **head, char *dir)
{

	list_t *new_int, *tail;

	new_int = malloc(sizeof(list_t));

	if (new_int == NULL)
		return (NULL);

	new_int->dir = dir;
	new_int->next = NULL;

	if (*head == NULL)
	{
		*head = new_int;
	}

	else
	{
		tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new_int;
	}
	return (new_int);
}


/**
 * free_list - frees a list_t list.
 * @head: pointer to the head of the list
 *
 * Return: nothing
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
