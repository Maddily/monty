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
	if (strcmp("0", argument) == 0 || atoi(argument))
	{
		if (strcmp("0", argument) == 0)
			arg = 0;
		else if (atoi(argument))
			arg = atoi(argument);
	}
	else if (atoi(argument) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	/*Create a new node and push it*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/*Should send a sign to the main function to exit itself with EXIT_FAILURE?*/
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	new_node->prev = NULL;
	/*Empty stack*/
	if (*our_stack == NULL)
	{
		new_node->next = NULL;
	}
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
