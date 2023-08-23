#include "monty.h"
/**
 * process_add - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the input file
 */
void process_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack != NULL && (*stack)->next != NULL)
	{
	result = pop(stack, line_number) + pop(stack, line_number);
	push(stack, result);
	}
	else
	{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
}

/**
 * process_nop - Does nothing.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the input file
 */
void process_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
