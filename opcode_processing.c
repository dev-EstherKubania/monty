#include "monty.h"

/**
 * process_push_pop - Process push and pop instructions.
 * @stack: Pointer to the top of the stack
 * @arg: Argument value
 * @line_number: Line number in the input file
 */
void process_push_pop(stack_t **stack, int arg, unsigned int line_number)
{
	if (arg == 0 || !stack)
	{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	push(stack, arg);
}

/**
 * process_print - Prints the top element of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the input file
 */
void process_print(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
	printf("%d\n", (*stack)->n);
	}
	else
	{
	fprintf(stderr, "L%u: can't print, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
}

/**
 * process_pall - Prints all elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the input file
 */
void process_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
	(void)line_number;
}

/**
 * process_pint - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the input file
 */
void process_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
	printf("%d\n", (*stack)->n);
	}
	else
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
}

/**
 * process_swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the input file
 */
void process_swap(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
	}
	else
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
}

