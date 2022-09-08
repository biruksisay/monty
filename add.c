#include "monty.h"
/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = result;
}
