#include "monty.h"
/**
 * free_monty - function to function to match the inserted command
 * @head: Parameter type struc
 * @vars: parameter type struc]
 */

void free_monty(vars_t *vars, stack_t *head)
{
	free_dlistint(head);
	free(vars->buffer);
	free(vars->arrays);
	free(vars->tokens);
}
