#include "monty.h"
char rotl_monty(vars_t *vars, stack_t **head)
{
    stack_t *tmp = *head;
    stack_t *set = *head;
    UNUSED(vars);
    *head = tmp->next;
    (*head)->prev = NULL;
    while(set->next != NULL)
    {
        set = set->next;
    }
    set->next = tmp;
    tmp->prev = set;
    tmp->next = NULL;
    return(0);
}
char rotr_monty(vars_t *vars, stack_t **head)
{
  int i = 0;
  int count = 0;
  stack_t *node = *head;
  stack_t *vodka = NULL;
  UNUSED(vars);
  if(node == NULL)
    return(0);
  while(node->next != NULL)
  {
    node = node->next;
    count++;
  }
  *head = node;
  while(i < count)
  {
    vodka = node->prev;
    vodka->next = NULL;
    node->prev = NULL;
    node->next = vodka;
    node = node->next;
    i++;
  }
  i = 0;
  node = *head;
  while(i < count)
  {

    vodka = node->next;
    vodka->prev = node;
    node =node->next;
    vodka = vodka->next;
    i++;
  }
  return(0);
}

char add_node_end(vars_t *vars, stack_t **head)
{
	stack_t *new_node = NULL;
	stack_t *vodka = *head;

    UNUSED(vars);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
	}
	new_node->n = atoi(vars->tokens[1]);
	new_node->next = NULL;
	if (*head != NULL)
	{
		while (vodka->next != NULL)
		{
			vodka = vodka->next;
		}
		vodka->next = new_node;
	} else
	{
		*head = new_node;
	}
	new_node->prev = vodka;
	return (0);
}
char mode_monty(vars_t *vars, stack_t **head)
{
    UNUSED(head);
    if(strcmp("stack",vars->tokens[0]) == 0)
    {
        vars->mode = "stack";
    } else
    {
        vars->mode = "queque";
    }
    return(0);
}
