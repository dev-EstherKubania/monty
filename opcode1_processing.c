#include "monty.h"

/**
 * process_add - adds the top two elements of the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_add(stack_t **stack, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		process_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}

/**
 * process_mod - computes the remainder of the division
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_mod(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
	exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%u: division by 0\n", line_num);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	process_pop(stack, line_num);
}
/**
 * process_queue - prints the top
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
*/
void process_queue(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
	bus.lifi = 1;
}
/**
 * process_rotr - rotates the stack to the bottom
 * @stack: head pointer of the stack
 * @line_num: line number of the file
 * Return: nothing
 */

void process_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	return;

	while (temp->next)
	temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;

	(void)line_num;
}

