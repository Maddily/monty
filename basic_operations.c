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
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*our_stack)->n);
}

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
		free_our_stack(*our_stack);
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
