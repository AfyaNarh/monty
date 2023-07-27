#include "monty.h"
/**
  * process_line - function that processes lines in a monty file
  * @line: lines in the monty file
  * @line_number: line number of lines in the monty file
  * @stack: stack
  * Return: Void
  */
void process_line(const char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode;
	char *argument;
	int num;

	opcode = strtok((char *)line, " \t\n");
	argument = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		if (argument == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		num = atoi(argument);
		if (num == 0 && strcmp(argument, "0") != 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, num);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

}
