#include "monty.h"

/**
 * implement_enqueue - Enqueues data in a queue
 *
 * @our_queue: A pointer to a pointer pointing to the front of a queue
 * @arg: opcode argument (data to be added to the queue)
*/

void implement_enqueue(stack_t **our_queue, int arg)
{
	stack_t *rear, *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_our_stack(*our_queue);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = arg;
	if (*our_queue == NULL) /*If queue is empty*/
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*our_queue = new_node;
	}
	else
	{
		rear = *our_queue;
		while (rear->next != NULL)
			rear = rear->next;
		rear->next = new_node;
		new_node->next = NULL;
		new_node->prev = rear;
	}
}

/**
 * implement_dequeue - Enqueues data in a queue
 *
 * @our_queue: A pointer to a pointer pointing to the front of a queue
*/

void implement_dequeue(stack_t **our_queue)
{
	stack_t *front;

	front = *our_queue;

	*our_queue = (*our_queue)->next;
	free(front);
}
