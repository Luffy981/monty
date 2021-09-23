build:
	gcc -Wall -Werror -Wextra -pedantic -std=c90  stack_monty.c get_op_func.c main.c monty_list.c read_file.c tokenizer.c -o monty -g
