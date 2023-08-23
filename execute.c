#include "monty.h"

/**
 * execute - Executes the Monty ByteCode instructions from a file.
 * @filename: Name of the input file
 */
void execute(const char *filename)
{
	stack_t *stack;
	char line[100];
	unsigned int line_number = 0;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	stack = NULL;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		execute_instruction(&stack, line, line_number);
	}
	fclose(file);
}

/**
 * execute_instruction - Executes a single instruction from a line.
 * @stack: Pointer to the top of the stack
 * @line: Line containing the instruction
 * @line_number: Line number in the input file
 */
void execute_instruction(stack_t **stack, char *line, unsigned int line_number)
{
	char opcode[10];
	int arg;

	if (sscanf(line, "%s %d", opcode, &arg) == 2)
	{
	if (strcmp(opcode, "push") == 0 || strcmp(opcode, "POP") == 0)
	{
	process_push_pop(stack, arg, line_number);
	}
	else if (strcmp(opcode, "print") == 0)
	{
	process_print(stack, line_number);
	}
	else
	{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
	}
	}
	else if (strcmp(opcode, "pall") == 0)
	{
	process_pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
	process_pint(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
	process_swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
	process_add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
	process_nop(stack, line_number);
	}
}

