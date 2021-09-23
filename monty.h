#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define UNUSED(x)  (void)(x)

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *  struct arguments - Struct to save variables
 * @buffer: Input text
 * @arrays: Array of arrays of pointers
 * @tokens: Token stored strings
 * @line_number: line number
 * @mode: mode
 */
typedef struct arguments
{
	char *buffer;
	char **arrays;
	char **tokens;
	int line_number;
	char *mode;
} vars_t;

/**
 * struct words - opcode and its function
 * @word: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct words
{
	char *word;
	char (*f)(vars_t *, stack_t **);
} word_t;

int main(int argc, char **argv);
char *file_read(char *filename);
char add_dnodeint(vars_t *list, stack_t **);
char  print_dlistint(vars_t *list, stack_t **);
void *fill_an_array(void *str, char c, size_t len);
void *_memcpy(char *dest, char *src, size_t n);
void *_realloc(void *str, size_t old_size, size_t new_size);
char *str_tok(char *buffer, char *d);
char **tokenizer(char *buffer, char *delimiter);
char (*get_op_fuctions(vars_t *m, stack_t **r))(vars_t *n, stack_t **r);
void free_dlistint(stack_t *head);
int check_int(char *str);
char print_nodeint_at_stack(vars_t *vars, stack_t **head);
char pop_nodeint_at_stack(vars_t *vars, stack_t **head);
char add_monty(vars_t *vars, stack_t **head);
char nop_monty(vars_t *vars, stack_t **head);
char sub_monty(vars_t *vars, stack_t **head);
char div_monty(vars_t *vars, stack_t **head);
char mul_monty(vars_t *vars, stack_t **head);
char mod_monty(vars_t *vars, stack_t **head);
char comment_monty(vars_t *vars, stack_t **head);
char pchar_monty(vars_t *vars, stack_t **head);

char swap_monty(vars_t *vars, stack_t **head);
char pstr_monty(vars_t *vars, stack_t **head);
char rotl_monty(vars_t *vars, stack_t **head);
char rotr_monty(vars_t *vars, stack_t **head);
char add_node_end(vars_t *vars, stack_t **head);
char mode_monty(vars_t *vars, stack_t **head);
char push_monty(vars_t *vars, stack_t **head);





int len_stack(stack_t **head);

#endif
