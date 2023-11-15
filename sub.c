#include "monty.h"

/**
 * sub_top_elements - subtracts top element from second element
 * @our_stack: the stack
 * @line_number: line being read
 */

void sub_top_elements(stack_t **our_stack, unsigned int line_number)
{
	int difference, top_n, second_n;
	stack_t *top_element;
	stack_t *second_element;

	if (get_stack_length(our_stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_our_stack(our_stack);
		exit(EXIT_FAILURE);
	}

	top_element = (*our_stack);
	second_element = (*our_stack)->next;

	top_n = top_element->n;
	second_n = second_element->n;
	difference = second_n - top_n;

	second_element->n = difference;
	second_element->prev = NULL;

	free(top_element);
	(*our_stack) = second_element;
}
