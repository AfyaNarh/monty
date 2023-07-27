#include "monty.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments passed
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t bufsize = 0;
	unsigned int line_number = 1;
	stack_t *temp;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &bufsize, file) != -1)
	{
		process_line(line, line_number, &stack);
		line_number++;
	}
	free(line);
	fclose(file);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
