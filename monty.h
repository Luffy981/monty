#ifndef  _MONTY_H_
#define  _MONTY_H_

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



typedef struct arguments
{
	char *buffer;
	char **arrays;
	char **tokens;
} vars_t;

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


#endif
