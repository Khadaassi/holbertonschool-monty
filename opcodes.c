#include "monty.h"

/**
 * opcodes - compares opcodes to sub-functions and call it
 * @stack: pointer to the stack
 * @line_number: line number in the file
 * @opcode: opcode to compare
 */
void opcodes(stack_t **stack, unsigned int line_number, char *opcode)
{
	int index;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (index = 0; opcodes[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
		{
			opcodes[index].f(stack, line_number);
			return;
		}
	}
	if (opcodes[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
