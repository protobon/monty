#include "monty.h"

/**
  * pint - prints value at top of the stack
  * @stack: doubly linked list
  * @ln: line number
  */
void pint(stack_t **stack, unsigned int ln)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't print, stack empty\n", ln);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
