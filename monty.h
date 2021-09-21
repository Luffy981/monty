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
	char *head;
} vars_t;

typedef struct words
{
	char *word;
	void (*f)(vars_t);
} word_t;

char *file_read(char *filename);
vars_t *add_dnodeint(vars_t *list);
size_t print_dlistint(vars_t *list);
void *fill_an_array(void *str, char c, size_t len);
void *_memcpy(char *dest, char *src, size_t n);
void *_realloc(void *str, size_t old_size, size_t new_size);
char *str_tok(char *buffer, char *d);
void (*get_op_fuctions(vars_t *m))(vars_t *n);
int main(int argc, char **argv, char **env);
char **tokenizer(char *buffer, char *delimiter);


#endif
