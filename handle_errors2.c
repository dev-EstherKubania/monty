#include "monty.h"
/**
 * process_pint_err - error message for an empty stack
 * @line_num: Line number where the error occurred
 *
 */
void process_pint_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * process_pop_err - error message for popping an empty stack
 * @line_num: Line number where the error occurred
 *
 */
void process_pop_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * process_swap_err - error message for swapping an insufficient stack
 * @line_num: Line number where the error occurred
 *
 */
void process_swap_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * process_add_err - error message for insufficient elements to add
 * @line_num: Line number where the error occurred
 *
 */
void process_add_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
/**
 * process_sub_err - error message for insufficient elements to subtract
 * @line_num: Line number where the error occurred
 *
 */
void process_sub_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
