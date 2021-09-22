#include "monty.h"
void free_dlistint(stack_t *head)
{
	stack_t *tmp = head;

	if (head == NULL)
	{
		return;
	}
	free_dlistint(head->next);
	free(tmp);
}
int main( __attribute__((unused)) int argc, char **argv)
{
	vars_t vars = {NULL};
	char *delim = "\n";
	char (*f)(vars_t *r, stack_t **p);
	int a;
	stack_t *head = NULL;
	vars.buffer = file_read(argv[1]);
	/* push 3 \n push 4  \n pall \n pop \n */
	vars.arrays = tokenizer(vars.buffer, delim);
	/*
	  push 3
	  push 4
	  pall
	  pop */
	if (vars.arrays == NULL)
	{
		printf("Data invalid");
	} else
	{
		for(a = 0 ; vars.arrays[a]  != NULL ; a++)
		{
			vars.tokens = tokenizer(vars.arrays[a], " ");
			f = get_op_fuctions(&vars, &head);
			if (f == NULL)
			{
				printf("No available function");
			} else
			{
				f(&vars, &head);
			}
            free(vars.tokens);
		}
	}
    free(vars.arrays);
    free(vars.buffer);
    free_dlistint(head);
	return(1);
}
