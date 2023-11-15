#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list that represents a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX Monty project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX Monty project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals_s - opcode argument and file
 *
 * @argument: A pointer to the opcode argument
 * @file: A pointer to a file
 * @is_stack: A flag indicating whether this is a stack or not
 * @is_queue: A flag indicating whether this is a queue or not
*/

typedef struct globals_s
{
	char *argument;
	FILE *file;
	bool is_stack;
	bool is_queue;
} globals_t;

#define UNUSED(x) (void)(x)
#define DELIMITER " \t\n"

extern globals_t globals;

/*Process lines*/
void split_line(char *line, unsigned int line_number, stack_t **our_stack);
bool check_blank(char *line);
bool check_opcode(char *string, instruction_t *instructions,
		size_t num_instructions);

/*helper functions*/
int get_stack_length(stack_t **our_stack);
bool validate_argument(void);
void free_our_stack(stack_t *our_stack);

/*Operations*/
void push_to_stack(stack_t **our_stack, unsigned int line_number);
void print_all_stack(stack_t **our_stack, unsigned int line_number);
void implement_nop(stack_t **our_stack, unsigned int line_number);
void print_top_element(stack_t **our_stack, unsigned int line_number);
void pop_top_element(stack_t **our_stack, unsigned int line_number);
void swap_top_elements(stack_t **our_stack, unsigned int line_number);
void add_top_elements(stack_t **our_stack, unsigned int line_number);
void sub_top_elements(stack_t **our_stack, unsigned int line_number);
void mul_top_elements(stack_t **our_stack, unsigned int line_number);
void div_top_elements(stack_t **our_stack, unsigned int line_number);
void mod_top_elements(stack_t **our_stack, unsigned int line_number);
void implement_pchar(stack_t **our_stack, unsigned int line_number);
void implement_pstr(stack_t **our_stack, unsigned int line_number);
void implement_rotl(stack_t **our_stack, unsigned int line_number);
void implement_rotr(stack_t **our_stack, unsigned int line_number);
void implement_queue(stack_t **our_stack, unsigned int line_number);
void implement_enqueue(stack_t **our_queue, int arg);
void implement_dequeue(stack_t **our_queue);
void implement_stack(stack_t **our_stack, unsigned int line_number);


#endif
