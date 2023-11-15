#include "monty.h"

/**
 * push_to_stack - Pushes data to a stack
 *
 * @our_stack: A pointer to a stack
 * @line_number: The number of a line in a file
*/
void push_to_stack(stack_t **our_stack, unsigned int line_number)
{
	stack_t *new_node;
	int arg;

	/*Check if the argument is valid*/
	if (globals.argument != NULL
	&& (strcmp("0", globals.argument) == 0 || validate_argument()))
	{
		if (strcmp("0", globals.argument) == 0)
			arg = 0;
		else if (validate_argument())
			arg = atoi(globals.argument);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	/*Create a new node and push it*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	new_node->prev = NULL;
	/*Empty stack*/
	if (*our_stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *our_stack;
		(*our_stack)->prev = new_node;
	}
	*our_stack = new_node;
}
/**
 * print_all_stack - Prints the data in a stack
 *
 * @our_stack: A pointer to a stack
 * @line_number: The number of a line in a file
*/
void print_all_stack(stack_t **our_stack, unsigned int line_number)
{
	stack_t *current;

	UNUSED(line_number);

	/*Print only if not empty*/
	if (*our_stack != NULL)
	{
		current = *our_stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
/**
 * validate_argument - Checks if the argument is a valid numeral string
 *
 * Return: true if valid, false otherwise
*/
bool validate_argument(void)
{
	char *invalid_char;
	long result;

	UNUSED(result);
	invalid_char = NULL;
	result = strtol(globals.argument, &invalid_char, 10);

	if (*invalid_char != '\0')
		return (false);

	return (true);
}
