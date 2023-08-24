#include "monty.h"

/**
 * process_nop - does nothing
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
/**
 * process_mul - multiplies the second top element with the top element
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_mul(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	process_pop(stack, line_num);
}
/**
 * process_swap - swaps the top two elements of the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	process_swap_err(line_num);

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if (temp->next)
	temp->next->prev = temp;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
/**
 * process_pop - removes the top element from the stack
 * @stack: head pointer of the stack
 * @line_num: line number for the file
 * Return: nothing
 */
void process_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	process_pop_err(line_num);

	*stack = (*stack)->next;
	free(temp);
}
/**
 * process_push - adds a new element to the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void process_push(stack_t **stack, unsigned int line_num)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
	if (bus.arg[0] == '-')
	j++;
	for (; bus.arg[j] != '\0'; j++)
	{
	if (bus.arg[j] > 57 || bus.arg[j] < 48)
	flag = 1;
	}
	if (flag == 1)
	{
	fclose(bus.file);
	free(bus.content);
	process_free_stack(*stack);
	process_push_err(line_num);
	}
	}
	else
	{
	fclose(bus.file);
	free(bus.content);
	process_free_stack(*stack);
	process_push_err(line_num);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
	process_addnode(stack, n);
	else
	process_addqueue(stack, n);
}

