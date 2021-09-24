#include "monty.h"

/**
 * len_stack - item counter in a stack
 * @head: double stack pointer
 * Return: counter
 */
int len_stack(stack_t **head)
{
	int count = 0;
	stack_t *stack = *head;

	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/**
 * pstr_monty - prints the string starting at the top of the stack,
 * followed by a new line
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char pstr_monty(vars_t *vars, stack_t **head)
{
	char *buffer = NULL;
	size_t m = 1;
	size_t i = 0;
	stack_t *stack = *head;

	UNUSED(vars);
	if (stack == NULL)
	{
		putchar('\n');
		return (1);
	}
	buffer = malloc(sizeof(char) * m);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
        free_monty(vars, *head);
		exit(EXIT_FAILURE);
	}
	while (stack != NULL)
	{
		if (stack->n == 0 || stack->n < 0 || stack->n > 126)
		{
			i++;
			break;
		}
		buffer[i] = stack->n;
		stack = stack->next;
		i++;
		if (i >= m)
		{
			buffer = _realloc(buffer, sizeof(char) * i, sizeof(char) * (i + 1));
			if (buffer == NULL)
			{
				fprintf(stderr, "Error: realloc failed\n");
                free_monty(vars, *head);
				exit(EXIT_FAILURE);
			}
		}
	}
	buffer[i] = '\0';
	printf("%s\n", buffer);
    free(buffer);
	return (0);
}

/**
 * pop_nodeint_at_stack - removes the top element of the stack
 * @vars : index of the node, starting at 0
* @head: Pointer to head list
* Return: Return count
 */
char pop_nodeint_at_stack(vars_t *vars, stack_t **head)
{
	stack_t *tmp;

	UNUSED(vars);
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", vars->line_number);
        free_monty(vars, *head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = NULL;
	}
	free(tmp);
	return (1);
}
