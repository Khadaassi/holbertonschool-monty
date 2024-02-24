#include "monty.h"

/**
 * free_stack - free the full stack.
 * @stack: pointer to the stack
*/
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *node;

	while (current != NULL)
	{
		node = current;
		current = current->next;
		free(node);
	}
	*stack = NULL;
}
