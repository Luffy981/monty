#include "monty.h"


char (*get_op_fuctions(vars_t *m, stack_t **r))(vars_t *n, stack_t **r)
{
	int i;
	
    word_t op[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint},
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
