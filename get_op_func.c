#include "monty.h"
/**
 * get_op_fuctions - function to function to match the inserted command
 * @m: Parameter type struc
 * @r: parameter type struc]
 *
 * Return: Return count
 */

char (*get_op_fuctions(vars_t *m, stack_t **r))(vars_t *n, stack_t **r)
{
	int i;
	word_t op[] = {
		{"push", push_monty},
		{"pall", print_dlistint},
		{"pint", print_nodeint_at_stack},
		{"pop", pop_nodeint_at_stack},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"#", comment_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", mode_monty},
		{"queue", mode_monty},
		{NULL, NULL},
	};
	UNUSED(r);
	for (i = 0 ; op[i].f != NULL ; i++)
	{
		if (strcmp(op[i].word, m->tokens[0]) == 0)
			break;
	}
	return (op[i].f);
}
