#include "monty.h"

/**
 * add_monty - adds the top two elements of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char add_monty(vars_t *vars, stack_t **head)
{
	int sum = 0;
	stack_t *node = *head;
	stack_t *tmp = *head;
    int count;

    count = len_stack(&*head);

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	sum = node->n + node->next->n;
	node->next->n = sum;
	*head = node->next;
	node->next->prev = NULL;
	free(tmp);
	return (0);
}

/**
 * nop_monty - The opcode nop doesn’t do anything
 * @vars: stack quantity
 * @head: top stack
 * Return:  returns 0 if correct
 */
char nop_monty(vars_t *vars, stack_t **head)
{
	UNUSED(vars);
	UNUSED(head);
	return (0);
}

/**
 * sub_monty - subtracts the top element of the stack from the
 * second top element of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char sub_monty(vars_t *vars, stack_t **head)
{
	int sub = 0;
	stack_t *node = *head;
	stack_t *tmp = *head;
    int count;

    count = len_stack(&*head);

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	sub = node->next->n - node->n;
	node->next->n = sub;
	*head = node->next;
	node->next->prev = NULL;
	free(tmp);
	return (0);
}

/**
 * div_monty - divides the second top element of the stack by the top
 * element of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char div_monty(vars_t *vars, stack_t **head)
{
	int div = 0;
	stack_t *node = *head;
	stack_t *tmp = *head;
    int count;
    count = len_stack(&*head);

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	div = node->next->n / node->n;
	node->next->n = div;
	*head = node->next;
	node->next->prev = NULL;
	free(tmp);
	return (0);
}

/**
 * mul_monty - multiplies the second top element of the stack with the
 * top element of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char mul_monty(vars_t *vars, stack_t **head)
{
	int mul = 0;
	stack_t *node = *head;
	stack_t *tmp = *head;
    int count;
    count = len_stack(&*head);

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", vars->line_number);
		exit(EXIT_FAILURE);
	}
	mul = node->n * node->next->n;
	node->next->n = mul;
	*head = node->next;
	node->next->prev = NULL;
	free(tmp);
	return (0);
}
