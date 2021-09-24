#include "monty.h"

/**
 * free_dlistint - function to add elements to list
 * @head: Pointer of type list
 */
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

/**
 * main - Main function
 * @argc: Number of arguments
 * @argv: Array of arguments of main.
 * Return: 1 if succes
 */
int  main(int argc, char **argv)
{
	vars_t vars = {NULL};
	char *delim = "\n\t", (*f)(vars_t *r, stack_t **p);
	int a;
	stack_t *head = NULL;

	vars.mode = "stack";
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	vars.buffer = file_read(argv[1]);
	vars.arrays = tokenizer(vars.buffer, delim);
	if (vars.arrays == NULL)
		printf("Data invalid");
	else
	{
		for (a = 0 ; vars.arrays[a]  != NULL ; a++)
		{
			vars.line_number = a + 1;
			if (strcmp(vars.arrays[a], "salto") == 0)
				continue;
			vars.tokens = tokenizer(vars.arrays[a], " ");
			if (vars.tokens[0][0] == '#')
			{
				free(vars.tokens);
				continue;
			}
			f = get_op_fuctions(&vars, &head);
			if (f == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
					vars.line_number, vars.arrays[a]);
				free_monty(&vars, head);
				exit(EXIT_FAILURE);
			}
			else
				f(&vars, &head);
			free(vars.tokens);
		}
	}
    free_dlistint(head);
    free(vars.arrays);
    free(vars.buffer);
    if(!vars.tokens)
    {
	    free(vars.tokens);
    }
    exit(EXIT_FAILURE);
}
