# 🚀 0x19. C - Stacks, Queues - LIFO, FIFO
***
### Learning Objectives
***
#### General
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

### Requirements
***
#### General
* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c90
* All your files should end with a new line
* No more than 5 functions per file
* You are allowed to use the C standard library
* You allowed to use a maximum of one global variable

### 🎨 Style
***
* Your code should use the `Betty` style.

### 📚 More Info
***
#### Data structures
This data structure is used for this project

```C
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
```

```C
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
```

### ⚙️ Compilation & Output
***
The code is compiled as follows:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```

### 💻 The Monty language
***
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

####  Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```Bash
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```Bash
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

### :bookmark_tabs: Features
***
#### Opcodes
`monty` executes the following opcodes:

| Opcode | Description|
| --- | --- |
| `push` | Pushes an element to the stack. |
| `pall` |Prints all the values on the stack. |
| `pint` | Prints the value at the top of the stack. |
| `pop` | Removes the top element of the stack. |
| `swap` | Swaps the top two elements of the stack. |
| `queue` | Sets the format of the data to a queue (FIFO). |
| `stack` | Sets the format of the data to a stack (LIFO). |
| `nop` | Doesn't do anything. |
| `add` | Adds the top two elements of the stack. |
| `sub` | Subtracts the top element of the stack from the second top element of the stack. |
| `mul` | Multiplies the second top element of the stack with the top element of the stack. |
| `div` | Divides the second top element of the stack by the top element of the stack. |
| `mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack. |
| `pchar` | Prints the char at the top of the stack. |
| `pstr` | Prints the string starting at the top of the stack. |
| `rotl` | Rotates the stack to the top. |
| `rotr` | Rotates the stack to the bottom. |

### ✏️ Project files
***
The following files are those implemented in the FIFO and LIFO project:

| Files | Description |
| --- | --- |
| [free_monty.c](https://github.com/Luffy981/monty/blob/master/free_monty.c) |  Function to function to match the inserted command. |
| [get_op_func.c](https://github.com/Luffy981/monty/blob/master/get_op_func.c) | File where it is done in match with the functions. |
| [main.c](https://github.com/Luffy981/monty/blob/master/main.c) | Main function and memory free function. |
| [monty.h](https://github.com/Luffy981/monty/blob/master/monty.h) | Library used to work on project. |
| [monty_list.c](https://github.com/Luffy981/monty/blob/master/monty_list.c) | Opcode functions. |
| [monty_list1.c](https://github.com/Luffy981/monty/blob/master/monty_list1.c) | Opcode functions. |
| [monty_list2.c](https://github.com/Luffy981/monty/blob/master/monty_list2.c) | Opcode functions. |
| [monty_list3.c](https://github.com/Luffy981/monty/blob/master/monty_list3.c) | Opcode functions. |
| [read_file.c](https://github.com/Luffy981/monty/blob/master/read_file.c) | Function that opens the files to be viewed. |
| [stack_monty.c](https://github.com/Luffy981/monty/blob/master/stack_monty.c) | The default behavior of the program. |
| [tokenizer.c](https://github.com/Luffy981/monty/blob/master/tokenizer.c) | Functions used to manipulate strings. |

| Directory | Description |
| --- | --- |
| [bf](https://github.com/Luffy981/monty/tree/master/bf) | Brainfuck Advanced Project Folder which is an esoteric programming language. |

### ✒️ Autors
***
*Holberton School Students*

Jhon Flores - [Luffy981](https://github.com/Luffy981)

Geraldine Meneses - [nitaly31](https://github.com/nitaly31)
