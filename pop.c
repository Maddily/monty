#include "monty.h"

/**
 * _pop_func - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line being read
 */

void _pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *element;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	element = (*stack);
	/*right now top:*/
	/*top->next = NULL*/
	/*top->prev = element->prev*/
	/*top->n = element->n*/

	/*element before top*/
	/*top->prev->next = NULL*/
	/*top->prev->prev = top->prev->prev->prev*/

	/*no need to update prev value of element before top*/
	(*stack) = element->prev;
	if ((*stack) != NULL)
		element->prev->next = NULL;
	free(element);
	/*find element on the top of the list*/
	/*change prev and next*/
	/*remove top element*/
	/*LIFO*/
}
