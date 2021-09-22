#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define INSTRUCTIONS { \
	{"push", push},\
	{"pall", pall},\
	{"pint", pint},\
	{"pop", pop},\
	{"swap", swap},\
	{NULL, NULL} \
}

/**
  * struct help - global struct to hold argument of opcode
  * @data_struct: asd
  * @argument: arg of opcode
  * Description: asd
  */
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

/* opcodes */
void push(stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int ln);
void opcode(stack_t **stack, char *str, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);

stack_t *add_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

int is_digit(char *string);

#endif /* MONTY_H */
