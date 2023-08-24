#include "monty.h"

/**
 * process_free_stack - frees a doubly linked list
 * @stack: pointer to the head of the stack
 */
void process_free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
	temp = stack->next;
	free(stack);
	stack = temp;
	}
}

/**
 * process_addqueue - add node to the tail stack
 * @stack: head of the stack
 * @n: new_value
 * Return: no return
 */
void process_addqueue(stack_t **stack, int n)
{
	stack_t *new_stack, *temp;

	temp = *stack;
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
	printf("Error\n");
	}
	new_stack->n = n;
	new_stack->next = NULL;
	if (temp)
	{
	while (temp->next)
	temp = temp->next;
	}
	if (!temp)
	{
	*stack = new_stack;
	new_stack->prev = NULL;
	}
	else
	{
	temp->next = new_stack;
	new_stack->prev = temp;
	}
}

/**
 * process_addnode - add node to the head stack
 * @stack: head of the stack
 * @n: new_value
 * Return: no return
 */
void process_addnode(stack_t **stack, int n)
{

	stack_t *new_stack, *temp;

	temp = *stack;
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
	printf("Error\n");
	exit(0);
	}
	if (temp)
	temp->prev = new_stack;
	new_stack->n = n;
	new_stack->next = *stack;
	new_stack->prev = NULL;
	*stack = new_stack;
}
/**
 * process_stack - function that checks if the stack is in stack mode
 * @stack: head pointer of the stack
 * @line_num: line number of the file
 * Return: nothing
 */

void process_stack(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
	bus.lifi = 0;
}
