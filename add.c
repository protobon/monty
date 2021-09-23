#include "monty.h"

/**
  * add - adds top two values of the stack
  * @stack: head of stack
  * @ln: line number
  * Description: adds up last two and removes top node,
  * prints error if stack is shorter than two nodes
  */
void add(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;
	int a;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n + (*stack)->next->n;
	pop(stack, ln);
	(*stack)->n = a;
}
