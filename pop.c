#include "monty.h"

/**
 * pop_top_element - removes the top element of the stack
 * @our_stack: double pointer to the stack
 * @line_number: line being read
 */

void pop_top_element(stack_t **our_stack, unsigned int line_number)
{
	stack_t *element;

	if (*our_stack != NULL)
	{
		element = (*our_stack);
		(*our_stack) = element->next;
		free(element);
	}
	else
	{
		fprintf(stderr, "%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
