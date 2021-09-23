#include "monty.h"

/**
  * sub - substracts top from 2nd top element of stack
  * @stack: head of stack
  * @ln: line number
  * Description: adds up last two and removes top node,
  * prints error if stack is shorter than two nodes
  */
void sub(stack_t **stack, unsigned int ln)
{
	int a;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next->n - (*stack)->n;
	pop(stack, ln);
	(*stack)->n = a;
}
