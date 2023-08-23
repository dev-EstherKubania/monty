#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack
 * @value: Value to push onto the stack
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
	(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the input file
 * Return: The value of the popped element
 */
int pop(stack_t **stack, unsigned int line_number)
{
	int popped_value = (*stack)->n;
	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
	(*stack)->prev = NULL;
	}

	free(temp);
	return (popped_value);
}

