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
	if (globals.is_stack == true)
	{
		new_node = malloc(sizeof(stack_t)); /*Create a new node and push it*/
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_our_stack(*our_stack);
			fclose(globals.file);
			exit(EXIT_FAILURE);
		}
		new_node->n = arg, new_node->prev = NULL;
		if (*our_stack == NULL) /*Empty stack*/
			new_node->next = NULL;
		else
			new_node->next = *our_stack, (*our_stack)->prev = new_node;
		*our_stack = new_node;
	}
	else
		implement_enqueue(our_stack, arg); /*Add the value to the queue*/
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

	current = *our_stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * implement_rotl - Rotates the stack to the top
 *
 * @our_stack: A pointer to a stack
 * @line_number: The number of a line in a file
*/
void implement_rotl(stack_t **our_stack, unsigned int line_number)
{
	stack_t *last, *top;
	size_t i = 0;

	UNUSED(line_number);

	if (*our_stack != NULL)
	{
		last = *our_stack;

		while (last->next != NULL)
		{
			last = last->next;
			i++;
		}
		/*If there's more than one node in the stack*/
		if (i > 0)
		{
			top = *our_stack;
			*our_stack = (*our_stack)->next;
			(*our_stack)->prev = NULL;
			top->next = NULL;
			last->next = top;
			top->prev = last;
		}
	}
}

/**
 * implement_rotr - Rotates the stack to the bottom
 *
 * @our_stack: A pointer to a stack
 * @line_number: The number of a line in a file
*/

void implement_rotr(stack_t **our_stack, unsigned int line_number)
{
	stack_t *last;
	size_t i = 0;

	UNUSED(line_number);

	if (*our_stack != NULL)
	{
		last = *our_stack;

		while (last->next != NULL)
		{
			last = last->next;
			i++;
		}
		/*If there's more than one node in the stack*/
		if (i > 0)
		{
			last->prev->next = NULL;
			last->prev = NULL;
			last->next = *our_stack;
			(*our_stack)->prev = last;
			*our_stack = last;
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
