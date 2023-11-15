#include "monty.h"

/**
 * add_top_elements - adds the top two elements of the stack
 * @our_stack: double pointer to the stack
 * @line_number: line being read
 */

void add_top_elements(stack_t **our_stack, unsigned int line_number)
{
	int sum, top_n, second_n;
	stack_t *top_element;
	stack_t *second_element;

	if (get_stack_length(our_stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	top_element = (*our_stack);
	second_element = (*our_stack)->next;

	top_n = top_element->n;
	second_n = second_element->n;
	sum = top_n + second_n;

	second_element->n = sum;
	second_element->prev = NULL;

	free(top_element);
	(*our_stack) = second_element;
}
