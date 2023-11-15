#include "monty.h"

/**
 * mod_top_elements - finds rest of division of second top elemnt by top elemnt
 * @our_stack: the stack
 * @line_number: line being read
 */

void mod_top_elements(stack_t **our_stack, unsigned int line_number)
{
	int remainder, top_n, second_n;
	stack_t *top_element;
	stack_t *second_element;

	if (get_stack_length(our_stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	top_element = (*our_stack);
	second_element = (*our_stack)->next;

	top_n = top_element->n;
	second_n = second_element->n;

	if (top_n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	remainder = second_n % top_n;

	second_element->n = remainder;
	second_element->prev = NULL;

	free(top_element);
	(*our_stack) = second_element;
}
