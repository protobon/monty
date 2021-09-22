#include "monty.h"

void pop(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
	(*stack)->prev = NULL;
	free(tmp);
}
