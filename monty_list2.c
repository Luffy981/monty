#include "monty.h"

/**
 * mod_monty - computes the rest of the division of the second top element of
 * the stack by the top element of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char mod_monty(vars_t *vars, stack_t **head)
{
	int mod = 0;
	stack_t *node = *head;
	stack_t *tmp = *head;
	int count;

	count = len_stack(&*head);

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", vars->line_number);
		exit(EXIT_FAILURE);
	}

	mod = node->next->n % node->n;
	node->next->n = mod;
	*head = node->next;
	node->next->prev = NULL;
	free(tmp);
	return (0);
}
/**
 * comment_monty - Special character that represents a comment
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char comment_monty(vars_t *vars, stack_t **head)
{
	UNUSED(vars);
	UNUSED(head);
	return (0);
}

/**
 * pchar_monty - prints the char at the top of the stack, followed by a new
 * line
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char pchar_monty(vars_t *vars, stack_t **head)
{
	stack_t *node = *head;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", vars->line_number);
        free_monty(vars, *head);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", vars->line_number);
        free_monty(vars, *head);
		exit(EXIT_FAILURE);
	}
	putchar(node->n);
	putchar('\n');
	return (0);
}

/**
 * swap_monty - swaps the top two elements of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char swap_monty(vars_t *vars, stack_t **head)
{
	int tmp;
	int count;

	count = len_stack(&*head);

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
	return (0);
}
