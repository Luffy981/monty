#include "monty.h"
/**
 * add_dnodeint - function to add elements to list
 * @head: Pointer of type list_t
 *
 * @n: Pointer of type list_t
 *
 * Return: Return count
 */
char add_dnodeint(vars_t *list, stack_t **head)
{
	stack_t *new_node = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
	}
    if (list->tokens[1] == NULL || check_int(list->tokens[1]) == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", list->line_number);
        exit(EXIT_FAILURE);
    }
	new_node->n = atoi(list->tokens[1]);
	new_node->next = *head;
	new_node->prev = NULL;
	if (new_node->next != NULL)
	{
		new_node->next->prev = new_node;
	}
	*head = new_node;
	return(1);
}
int check_int(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] < 47 || str[i] > 57)
        {
            return (0);
        }
        i++;
    }
    return (1);
}
/**
 * print_dlistint - function to print all the elements of a list_t list
 * @h: Pointer of type list_t
 *
 * Return: Return count
 */
char  print_dlistint(__attribute__((unused))vars_t *list, stack_t **head)
{
	int count = 0;
	
    stack_t *node = *head;
    while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
		count++;
	}
	return(0);
}
/**
 * get_dnodeint_at_index  - function to add elements to list
 * @head: Pointer of type list_t
 * @index: Pointer of type list_t
 *
 * Return: Return count
 */
char print_nodeint_at_stack(vars_t *vars, stack_t **head)
{
    stack_t *node = *head;
    
    UNUSED(vars);
	if (node == NULL)
    {
        printf("L%d: can't pint, stack empty\n", vars->line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", node->n);
    return (0);
}

/**
 * delete_dnodeint_at_index - function to delete node at index
 * @index : index of the node, starting at 0
 * @head: Pointer to  head list
 *
 * Return: Return count
 */
char pop_nodeint_at_stack(vars_t *vars, stack_t **head)
{
	stack_t *tmp;

    UNUSED(vars);
	if (head == NULL || *head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", vars->line_number);
    }
	tmp = *head;
	*head = tmp->next;
	if (tmp->next != NULL)
    {
        tmp->next->prev = NULL;
    }
    free(tmp);
    return (1);
}

char add_monty(vars_t *vars, stack_t **head)
{
    int sum = 0;
    stack_t *node = *head;
    stack_t *tmp = *head;

    if (node->next == NULL || node == NULL)
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

char nop_monty(vars_t *vars, stack_t ** head)
{
    UNUSED(vars);
    UNUSED(head);
    return(0);
}

char sub_monty(vars_t *vars, stack_t **head)
{
    int sub = 0;
    stack_t *node = *head;
    stack_t *tmp = *head;

    if (node->next == NULL || node == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", vars->line_number);
        exit(EXIT_FAILURE);
    }
    sub = abs(node->n - node->next->n);
    node->next->n = sub;
    *head = node->next;
    node->next->prev = NULL;
    free(tmp);
    return (0);
}

char div_monty(vars_t *vars, stack_t **head)
{
    int div = 0;
    stack_t *node = *head;
    stack_t *tmp = *head;

    if (node->next == NULL || node == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", vars->line_number);
        exit(EXIT_FAILURE);
    }
    if(node->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", vars->line_number);
        exit(EXIT_FAILURE);
    }
    div = node->n / node->next->n;
    node->next->n = div;
    *head = node->next;
    node->next->prev = NULL;
    free(tmp);
    return (0);
}

char mul_monty(vars_t *vars, stack_t **head)
{
    int mul = 0;
    stack_t *node = *head;
    stack_t *tmp = *head;

    if (node->next == NULL || node == NULL)
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

char mod_monty(vars_t *vars, stack_t **head)
{
    int mod = 0;
    stack_t *node = *head;
    stack_t *tmp = *head;

    if (node->next == NULL || node == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", vars->line_number);
        exit(EXIT_FAILURE);
    }
    if(node->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", vars->line_number);
        exit(EXIT_FAILURE);
    }

    mod = node->n % node->next->n;
    node->next->n = mod;
    *head = node->next;
    node->next->prev = NULL;
    free(tmp);
    return (0);

}

char comment_monty(vars_t *vars, stack_t ** head)
{
    UNUSED(vars);
    UNUSED(head);
    return(0);
}

char pchar_monty(vars_t *vars, stack_t **head)
{
    stack_t *node = *head;
    
    UNUSED(vars);
    if (node->n < 0 || node->n >255)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range", vars->line_number);
        exit(EXIT_FAILURE);
    }
	if (node == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", vars->line_number);
        exit(EXIT_FAILURE);
    }
    putchar(node->n);
    putchar('\n');
    return (0);
}

char swap_monty(vars_t *vars, stack_t **head)
{
    int tmp;
    int count;
    count = len_stack(&*head);

    if(count < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", vars->line_number);
        exit(EXIT_FAILURE);
    }
    tmp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = tmp;
    return(0);
}

int len_stack(stack_t **head)
{
    int count = 0;
    stack_t *stack = *head;

	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

char pstr_monty(vars_t *vars, stack_t **head)
{
    char *buffer = NULL;
    size_t m = 1;
    size_t i = 0;
    stack_t *stack = *head;
    UNUSED(vars);
    if(stack == NULL)
    {
        putchar('\n');
        return(1);
    }
    buffer = malloc(sizeof(char) * m);
    if(buffer == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    while(stack != NULL)
    {
        if(stack->n == 0 || stack->n < 0 || stack->n > 255)
        {
            i++;
            break;
        }
        buffer[i] = stack->n;
        stack = stack->next;
        i++;
        if(i >= m)
        {
            buffer = _realloc(buffer,sizeof(char) * i, sizeof(char) * (i + 1));
            if(buffer == NULL)
            {
                fprintf(stderr, "Error: realloc failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    buffer[i] = '\0';
    printf("%s\n", buffer);
    return(0);
}

