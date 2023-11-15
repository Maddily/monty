#include "monty.h"

/**
 * split_line - Splits a line using delimiters
 *
 * @line: A pointer to a line in a file
 * @line_number: The line number
 * @our_stack: A pointer to a stack
*/
void split_line(char *line, unsigned int line_number, stack_t **our_stack)
{
	char *string;
	instruction_t instructions[] = {
		{"push", push_to_stack},
		{"pall", print_all_stack},
		{"pint", print_top_element},
		{"pop", pop_top_element},
		{"swap", swap_top_elements},
		{"add", add_top_elements},
		{"sub", sub_top_elements},
		{"mul", mul_top_elements},
		{"nop", implement_nop},
		{"pchar", implement_pchar},
		{"pstr", implement_pstr}
	};
	size_t i, num_instructions;

	num_instructions = sizeof(instructions) / sizeof(instructions[0]);
	string = strtok(line, DELIMITER);
	if (check_opcode(string, instructions, num_instructions))
	{
		globals.argument = strtok(NULL, DELIMITER);
		for (i = 0; i < num_instructions; i++)
		{
			if (strcmp(string, instructions[i].opcode) == 0)
			{
				instructions[i].f(our_stack, line_number);
				break;
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, string);
		exit(EXIT_FAILURE);
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
/**
 * implement_nop - Implements the nop opcode
 *
 * @our_stack: A pointer to a stack
 * @line_number: The number of a line in a file
*/
void implement_nop(stack_t **our_stack, unsigned int line_number)
{
	UNUSED(our_stack);
	UNUSED(line_number);
}
/**
 * implement_pchar - Implements the pchar opcode
 *
 * @our_stack: A pointer to a stack
 * @line_number: The number of a line in a file
*/
void implement_pchar(stack_t **our_stack, unsigned int line_number)
{
	if (*our_stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*our_stack)->n < 33 || (*our_stack)->n > 126)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*our_stack)->n);
}
/**
 * implement_pstr - Implements the pstr opcode
 *
 * @our_stack: A pointer to a stack
 * @line_number: The number of a line in a file
*/
void implement_pstr(stack_t **our_stack, unsigned int line_number)
{
	stack_t *current;

	UNUSED(line_number);

	if (*our_stack == NULL)
		printf("\n");
	else
	{
		current = *our_stack;

		while (current != NULL)
		{
			if (current->n == 0 || current->n < 0 || current->n > 127)
			{
				break;
			}
			printf("%c", current->n);
			current = current->next;
		}
		printf("\n");
	}
}
