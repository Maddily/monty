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
		if (globals.is_stack == true)
		{
			element = (*our_stack);
			(*our_stack) = element->next;
			free(element);
		}
		else
			implement_dequeue(our_stack);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
}
