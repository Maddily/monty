#include "monty.h"

/**
 * _add_func - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line being read
 */

void _add_func(stack_t **stack, unsigned int line_number)
{
	int sum, top_n, second_n;
	stack_t *top_element;
	stack_t *second_element;

	if (get_stack_length(*stack) < 2)
	{
		fprintf(stderr, "%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Get the top two elements of the stack*/
	top_element = (*stack);
	second_element = (*stack)->next;

	/*Add the values of the top two elements together.*/
	top_n = top_element->n;
	second_n = second_element->n;
	sum = top_n + second_n;

	/*Store the result in the second top element*/
	second_element->n = sum;

	/*Remove the top element from the stack.*/
	second_element->prev = NULL;
	/*free memory for deleted element*/
	free(top_element);
}
