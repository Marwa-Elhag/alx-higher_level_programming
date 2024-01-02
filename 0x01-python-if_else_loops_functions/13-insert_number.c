#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - to insert node
 * @head: address
 * @number: inserting number
 * Return: Success
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);
	current_node = *head;
	new_node->n = number;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	if (current_node->n > number)
	{
		new_node->next = current_node;
		*head = new_node;
		return (new_node);
	}

	while (current_node->next != NULL)
	{
		if (current_node->next->n > number)
		{
			new_node->next = current_node->next;
			current_node->next = new_node;
			return (new_node);
		}
		current_node = current_node->next;
	}
	current_node->next = new_node;
	return (new_node);
}
