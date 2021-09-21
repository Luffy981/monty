#include "monty.h"

int main(int argc, char **argv)
{
	vars_t vars = {NULL};
	size_t len_buff;
	stack_t *head = NULL;
	char **tokens = NULL;
	char *delim = "\n";
	int read;
	char (*f)(vars_t *r);
	int a;

	vars.buffer = file_read(argv[1]);
	/* push 3push 4  \n pall \n pop \n */
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
		for(a = 0 ; m->vars != NULL ; a++)
		{
			m->tokens = tokenizer(m->arrays[a], " ");
				/*
				  push
				  3*/
				f = get_op_fuctions(&vars);
			if (f == NULL)
			{
				printf("No available function");
			} else
			{
				f(&vars);
			}
			free(tokens);
		}
	}
}
