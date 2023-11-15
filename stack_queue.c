#include "monty.h"

/**
 * stack_func - sets the format of the data to a stack (LIFO)
 * @our_stack: double pointer to the stack
 * @line_number: line being read
 */

void stack_func(stack_t **our_stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if (globals.mode != STACK_MODE)
	{
		while ((*our_stack) != NULL)
		{
			push_to_stack(&temp, (*our_stack)->n);
			(*our_stack) = (*our_stack)->next;
		}
	}
	*our_stack = temp;
}

/**
 * queue_func - sets the format of the data to a queue (FIFO).
 * @our_stack: double pointer to the stack
 * @line_number: line being read
 */

void queue_func(stack_t **our_stack, unsigned int line_number)
{
	stack_t *front = NULL, *rear = NULL;
	(void)line_number;

	if (globals.mode != QUEUE_MODE)
	{
		while ((*our_stack) != NULL)
		{
			enqueue(&front, &rear, (*our_stack)->n);
			(*our_stack) = (*our_stack)->next;
		}
	}
	*our_stack = front;
}

/**
 * enqueue - add element to the rear of the queue
 * @front: front of queue/ first element
 * @rear: end of the queue/ last element
 * @data: n value of the node
 */

void enqueue(stack_t **front, stack_t **rear, int data)
{
	stack_t *new_element = malloc(sizeof(stack_t));

	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_element->n = data;
	new_element->next = NULL;

	if (*rear == NULL)
	{
		*front = new_element;
		*rear = new_element;
	}
	else
	{
		(*rear)->next = new_element;
		*rear = new_element;
	}
}

/**
 * switch_stack_queue_mode - switches modes
 * @our_stack: A pointer to a stack
 * @line_number: number of the line being read
 */

void switch_stack_queue_mode(stack_t **our_stack, unsigned int line_number)
{
	UNUSED(line_number);
	if (globals.mode == STACK_MODE)
	{
		globals.mode = QUEUE_MODE;
		queue_func(our_stack, line_number);
	}
	else if (globals.mode == QUEUE_MODE)
	{
		globals.mode = STACK_MODE;
		stack_func(our_stack, line_number);
	}
}
