#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Entry point of the Monty ByteCode interpreter.
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
	return (EXIT_FAILURE);
	}

	execute(argv[1]);

	return (EXIT_SUCCESS);
}
