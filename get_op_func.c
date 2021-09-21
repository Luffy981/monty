#include "monty.h"

/**
 */
void (*get_op_fuctions(vars_t *m))(vars_t *n)
{
	int i;
	int a;
	char **tokens = NULL
		word_t op[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint},
		/*{"pop",  pop_nodeint_at_stack},
		  {"pint", print_nodeint_at_stack},*/
		{NULL,NULL},
	};
	for(a = 0 ; m->vars != NULL ; a++)
	{
		tokens = tokenizer(m->tokens[0], " ");
		for (i = 0 ; op[i].f != NULL ; i++)
		{
			if(strcmp(op[i].word, tokens[0]) == 0)
				break;
			free(tokens);
		}
		return(op[i].f);
	}
}
