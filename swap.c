#include "monty.h"

/**
  * swap - swaps the top two elements of stack
  * @stack: head of stack
  * @ln: line number
  * Description: if stack contains less than two
  * elements, print error and exit failure
  */
void swap(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;
	int a;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	a = (*stack)->n;
	(*stack)->n = tmp->n;
	tmp->n = a;
}
