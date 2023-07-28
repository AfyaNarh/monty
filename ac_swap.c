#include "monty.h"
/**
  * swap - swaps the top two elements
  * @stack: double pointer to the top of the stack
  * @line_number: line number which has the swap opcode
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first_node, *second_node;
	int temp;

	if (stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = *stack;
	second_node = (*stack)->next;

	temp = first_node->n;
	first_node->n = second_node->n;
	second_node->n = temp;
}
