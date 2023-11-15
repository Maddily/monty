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
		free_our_stack(*our_stack);
		fclose(globals.file);
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

/**
 * div_top_elements - divides second top element of stack by top element
 * @our_stack: the stack
 * @line_number: line being read
 */

void div_top_elements(stack_t **our_stack, unsigned int line_number)
{
	int quotient, top_n, second_n;
	stack_t *top_element;
	stack_t *second_element;

	if (get_stack_length(our_stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	quotient = second_n / top_n;

	second_element->n = quotient;
	second_element->prev = NULL;

	free(top_element);
	(*our_stack) = second_element;
}

/**
 * mul_top_elements - subtracts top element of stack from second top element
 * @our_stack: the stack
 * @line_number: line being read
 */

void mul_top_elements(stack_t **our_stack, unsigned int line_number)
{
	int product, top_n, second_n;
	stack_t *top_element;
	stack_t *second_element;

	if (get_stack_length(our_stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_our_stack(*our_stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	top_element = (*our_stack);
	second_element = (*our_stack)->next;

	top_n = top_element->n;
	second_n = second_element->n;
	product = top_n * second_n;

	second_element->n = product;
	second_element->prev = NULL;

	free(top_element);
	(*our_stack) = second_element;
}

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
