#include "monty.h"

/**
 * print_top_element - prints value at the top of the stack
 * @our_stack: double pointer to the stack
 * @line_number: number on which the line is being read
 */

void print_top_element(stack_t **our_stack, unsigned int line_number)
{
	if ((*our_stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*our_stack)->n);
}
