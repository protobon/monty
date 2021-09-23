#include "monty.h"

/**
  * _div - divides second top by top element of stack
  * @stack: head of stack
  * @ln: line number
  * Description: divides and removes top node,
  * prints error if stack is shorter than two nodes
  */
void _div(stack_t **stack, unsigned int ln)
{
	int a;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	a = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, ln);
	(*stack)->n = a;
}
