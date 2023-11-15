#include "monty.h"

/**
 * swap_top_elements - swaps the top two elements of the stack.
 * @our_stack: double pointer to the stack
 * @line_number: line being read
 */

void swap_top_elements(stack_t **our_stack, unsigned int line_number)
{
	stack_t *top_element;
	stack_t *second_element;
	stack_t *third_element;

	if (get_stack_length(our_stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	/*if errors occur check swap logic below*/
	top_element = (*our_stack);
	second_element = (*our_stack)->next;
	third_element = (*our_stack)->next->next;
	/*also consider third elements pointers*/
	if (third_element != NULL)
		third_element->prev = top_element; /*point to top_element*/

	/*swap top to second element*/
	top_element->next = second_element->next;
	top_element->prev = second_element;
	/*n values remain unchanged*/
	second_element->next = top_element;
	second_element->prev = NULL;
	/*swap second element to top*/

	/*update *stack*/
	*our_stack = second_element;
}

/**
 * get_stack_length - calculates how many elements are in the stack
 * @our_stack: the stack
 * Return: number of elements in the stack
 */

int get_stack_length(stack_t **our_stack)
{
	int counter = 0;
	stack_t *temp = *our_stack;

	while (temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}
