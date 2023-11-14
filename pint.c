#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a \n
 * @stack: double pointer to the stack
 * @unsigned int line_number: number on which the line is being read
 */

void _pint_func(stack_t **stack, unsigned int line_number)
{
	/*check if stack if empty */
	if ((*stack) == NULL)
	{
		fprintf(stderr, "%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);	
	/*use stack data structure*/
	/*does not add or remove elements*/
	/*so no need to change prev or next values*/
	/*LIFO*/
}
