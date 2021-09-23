#include "monty.h"

void rotl(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *tmp = *stack, *last = *stack;

	while (last->next)
		last = last->next;
	last->next = tmp;
	*stack = (*stack)->next;
	tmp->prev = last;
	tmp->next = NULL;
	(*stack)->prev = NULL;
}
