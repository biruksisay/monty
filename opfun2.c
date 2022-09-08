#include "monty.h"
/**
 * swap - Delete top pf list
 * @stack: Doubly Linked List
 * @line_number: File line execution
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can not swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
/**
 * add - Add the top two elements of the stack
 * @stack: Doubly Linked List
 * @line_number: File line execution
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can not add, stack to short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}
/**
 * sub - Subtract the top two elemetns of the stack
 * @stack: Doubly Linked List
 * @line_number: File line execution
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can not sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}
/*8
 * divi - Divide the top two elements of the stack
 * @stck: Doubly Linked List
 * @line_number: File line execution
 * Return: Nothing
 */
void divi(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can not div, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}
