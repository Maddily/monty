#include "monty.h"

/**
 * split_line - Splits a line using delimiters
 *
 * @line: A pointer to a line in a file
 * @line_number: The line number
 * @our_stack: A pointer to a stack
*/
void split_line(char *line, unsigned int line_number, stack_t *our_stack)
{
	char *string;
	instruction_t instructions[] = {
		{"push", push_to_stack},
		{"pall", print_all_stack}
	};
	size_t i, num_instructions;

	num_instructions = sizeof(instructions) / sizeof(instructions[0]);
	string = strtok(line, " \t\n");
	while (string != NULL)
	{
		if (check_opcode(string, instructions, num_instructions))
		{
			argument = strtok(NULL, " \t\n");
			for (i = 0; i < num_instructions; i++)
			{
				if (strcmp(string, instructions[i].opcode) == 0)
				{
					instructions[i].f(&our_stack, line_number);
					break;
				}
			}
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, string);
			exit(EXIT_FAILURE);
		}
		string = strtok(NULL, " \t\n");
	}
}
/**
 * check_opcode - Checks if the received argument is a valid opcode
 *
 * @string: A pointer to a string
 * @instructions: An array of instruction structs
 * @num_instructions: The number of instructions in instructions array
 *
 * Return: true if it's valid, false if not
*/
bool check_opcode(char *string, instruction_t *instructions,
size_t num_instructions)
{
	size_t i;

	for (i = 0; i < num_instructions; i++)
	{
		if (strcmp(string, instructions[i].opcode) == 0)
			return (true);
	}

	return (false);
}
