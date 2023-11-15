#include "monty.h"

globals_t globals = {NULL, NULL, STACK_MODE};

/**
 * main - A monty bytecode interpreter
 *
 * @argc: Argument count
 * @argv: Arguments passed to the program
 *
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char line[500];
	char *filename = argv[1];
	unsigned int line_number = 1;
	stack_t *our_stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globals.file = fopen(filename, "r");
	if (globals.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), globals.file) != NULL)
	{
		if (check_blank(line))
			continue;
		split_line(line, line_number, &our_stack);
		line_number++;
	}
	free_our_stack(our_stack);
	fclose(globals.file);
	return (0);
}
/**
 * check_blank - Checks if a line is a blank line
 *
 * @line: A pointer to a string
 *
 * Return: true if the line is blank or consists of whitespace only,
 * false if the line isn't blank
*/
bool check_blank(char *line)
{
	size_t i;

	for (i = 0; i < strlen(line); i++)
	{
		if (!isspace((unsigned char)line[i]))
		{
			/*check for comments and treat it as a blank line*/
			if (line[i] == '#')
				return (true);
			return (false);
		}
	}

	return (true);
}
/**
 * free_our_stack - Frees the stack
 *
 * @our_stack: A pointer to the pointer pointing to the stack
*/
void free_our_stack(stack_t *our_stack)
{
	stack_t *current;

	if (our_stack != NULL)
	{
		while (our_stack != NULL)
		{
			current = our_stack->next;
			free(our_stack);
			our_stack = current;
		}
	}
}
