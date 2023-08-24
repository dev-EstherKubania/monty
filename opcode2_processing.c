#include "monty.h"

/**
 * process_sub - subtracts the top element from the second element
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_sub(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	process_sub_err(line_num);

	(*stack)->next->n -= (*stack)->n;
	process_pop(stack, line_num);
}

/**
 * process_div - divides the second top element
 *	with the top element of the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_div(stack_t **stack, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		process_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bus.file);
		free(bus.content);
		process_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}

/**
 * process_pall - prints opcode element on the stack from top down
 * @stack: the stack
 * @line_num: opcode line number
 * Return: nothing
 */
void process_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
	printf("%d\n", temp->n);
	temp = temp->next;
	}
	(void)line_num;
}

/**
 * process_pint - function that prints opcode element at the top of the stack
 * @stack: the stack
 * @line_num: opcode line number
 * Return: nothing
 */
void process_pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	process_pint_err(line_num);

	printf("%d\n", (*stack)->n);
}
/**
 * process_pchar - prints the ascii value of the char at the top of the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_pchar(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
	exit(EXIT_FAILURE);
	}
	if (!(*stack))
	{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
	exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

