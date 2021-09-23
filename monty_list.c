#include "monty.h"

/**
 * push_monty - pushes an element to the stack
 * @vars: Pointer of type vars_t
 * @head: Pointer of type stack_t
 * Return: Return count
 */
char push_monty(vars_t *vars, stack_t **head)
{
	if (strcmp(vars->mode, "stack") == 0)
	{
		add_dnodeint(vars, head);
	} else
	{
		add_node_end(vars, head);
	}
	return (0);
}

/**
 * add_dnodeint - function to add elements to list
 * @list: Pointer of type vars_t
 * @head: Pointer of type stack_t
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
	return (1);
}

/**
 * check_int - Validate that the values are integers
 * @str: pointer to string
 * Return: 1 if the function is correct
 */
int check_int(char *str)
{
	int i = 0;

	while (str[i] != '\0')
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
 * print_dlistint - print the entire stack list
 * @list: pointer of type vars_t
 * @head: Pointer of type stack_t
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
	return (0);
}
/**
 * print_nodeint_at_stack  - prints the last node in the stack
 * @vars: Pointer of type vars_t
 * @head: Pointer of type stack_t
 * Return: Return count
 */
char print_nodeint_at_stack(vars_t *vars, stack_t **head)
{
	stack_t *node = *head;

	UNUSED(vars);
	if (node == NULL)
	{
		printf("L%d: can't pint, stack empty\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", node->n);
	return (0);
}
