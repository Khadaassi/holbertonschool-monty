#include "monty.h"

/**
 * add - sum of the top two integers of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int sum = 0;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = node->n + node->next->n;
	node->next->n = sum;
	*stack = node->next;
	free(node);
}
