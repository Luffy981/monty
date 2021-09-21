#include "monty.h"
/**
 * add_dnodeint - function to add elements to list
 * @head: Pointer of type list_t
 * @n: Pointer of type list_t
 *
 * Return: Return count
 */
vars_t *add_dnodeint(vars_t *list)
{
	stack_t *new_node = list->head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = atoi(list->tokens[1]);
	new_node->next = list->head;
	new_node->prev = NULL;
	if (new_node->next != NULL)
	{
		new_node->next->prev = new_node;
	}
	list->head = new_node;
	return (list);
}
/**
 * print_dlistint - function to print all the elements of a list_t list
 * @h: Pointer of type list_t
 *
 * Return: Return count
 */
size_t print_dlistint(vars_t *list)
{
	int count = 0;

	while (list->head != NULL)
	{
		printf("%d\n", list->head->n);
		list->head = list->head->next;
		count++;
	}
	return (count);
}
/**
 * get_dnodeint_at_index  - function to add elements to list
 * @head: Pointer of type list_t
 * @index: Pointer of type list_t
 *
 * Return: Return count
 */
/*dlistint_t *print_nodeint_at_stack(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 1; i <= index; i++)
	{
		if (head == NULL)
		{
      printf("L<line_number>: can't pint, stack empty")
			exit(EXIT_FAILURE);
		}
		head = head->next;
    printf("%d\n", head->n);
	}
	return (head);
}*/

/**
 * delete_dnodeint_at_index - function to delete node at index
 * @index : index of the node, starting at 0
 * @head: Pointer to  head list
 *
 * Return: Return count
 */
/*int pop_nodeint_at_stack(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int counter = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	tmp = *head;
	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
		{
			tmp->next->prev = NULL;
		}
		free(tmp);
		return (1);
	}

	while (counter < index)
	{
		if (tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
		counter++;
	}
	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	free(tmp);
	return (1);
}
EXIT_FAILURE*/
