#include "monty.h"

/**
 * pall - function to print all elements of the stack
 * @stack: stack
 * Return: Void
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
