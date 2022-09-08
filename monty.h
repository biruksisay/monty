#ifndef monty_h
#define monty_h

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#define INSTRUCTIONS              \
{                           \
	{"push", push},       \
	{"pall", pall},	  \
	{"pint", pint},	  \
	{"pop", pop},     \
	{"swap", swap},   \
	{"nop", nop},     \
	{"div", _div},    \
	{"mul", _mul},    \
	{"add", _add},    \
	{"sub", _sub},    \
	{"mod", mod},     \
	{"pchar", pchar}, \
	{"pstr", pstr},   \
	{"rotl", rotl},   \
	{"rotr", rotr},   \
	{                     \
		NULL, NULL      \
	}                     \
}
/**
 * struct stack_s - Doubly Linked List representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 * Description: Doubly Linked List Node Structure for stack,
 * queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @d: function to handle the opcode
 * Dscription: Opcode and its function for stack,
 * queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct help - Argument for the current opcode
 * @data_struct: Stack mode, stack and queue
 * @argument: The argument of the string
 * Description: Global structure
 */
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);
void pint(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);
void nop(stack_t **stack, unsigned int line_cnt);

void _div(stack_t **stack, unsigned int line_cnt);
void _add(stack_t **stack, unsigned int line_cnt);
void _sub(stack_t **stack, unsigned int line_cnt);
void _mul(stack_t **stack, unsigned int line_cnt);
void mod(stack_t **stack, unsigned int line_cnt);

void pchar(stack_t **stack, unsigned int line_cnt);
void pstr(stack_t **stack, unsigned int line_cnt);
void rotl(stack_t **stack, unsigned int line_count);
void rotr(stack_t **stack, unsigned int line_count);

void opcode(stack_t **stack, char *str, unsigned int line_cnt);

int is_digit(char *string);
int isnumber(char *str);
#endif
