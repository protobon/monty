#include "monty.h"

void add(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;
	int a;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	a = (*stack)->n + tmp->n;
	tmp->n = a;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}
