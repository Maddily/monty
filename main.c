#include "monty.h"

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
	FILE *file;
	char line[500];
	char *filename = argv[1];
	unsigned int line_number = 1;
	stack_t *our_stack = NULL;

	if (argc != 2) /*to do: add a check for recieving more than 2 arguments*/
		/*suggested: if (argc != 2)*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (check_blank(line))
			continue;
		split_line(line, line_number, &our_stack);
		line_number++;
	}
	fclose(file);
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
			return (false);
	}

	return (true);
}
