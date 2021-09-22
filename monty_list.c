#include "monty.h"
/**
 * add_dnodeint - function to add elements to list
 * @head: Pointer of type list_t
 * @n: Pointer of type list_t
 *
 * Return: Return count
 */
char add_dnodeint(vars_t *list, stack_t **head)
{
	stack_t *new_node = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
	}
    if (list->tokens[1] == NULL || check_int(list->tokens[1]) == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", list->line_number);
        exit(EXIT_FAILURE);
    }
	new_node->n = atoi(list->tokens[1]);
	new_node->next = *head;
	new_node->prev = NULL;
	if (new_node->next != NULL)
	{
		new_node->next->prev = new_node;
	}
	*head = new_node;
	return(1);
}
int check_int(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] < 47 || str[i] > 57)
        {
            return (0);
        }
        i++;
    }
    return (1);
}
/**
 * print_dlistint - function to print all the elements of a list_t list
 * @h: Pointer of type list_t
 *
 * Return: Return count
 */
char  print_dlistint(__attribute__((unused))vars_t *list, stack_t **head)
{
	int count = 0;
	
    stack_t *node = *head;
    while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
		count++;
	}
	return(0);
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
