#include "monty.h"

/**
  * rotl - rotates stack to the top
  * @stack: head of stack
  * @ln: line number, unused
  * Description: top element becomes last one,
  * second element becomes first, rotl never fails
  */
void rotl(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *tmp = *stack, *last = *stack;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (last->next)
		last = last->next;

	last->next = tmp;
	*stack = (*stack)->next;
	tmp->prev = last;
	tmp->next = NULL;
	(*stack)->prev = NULL;
}
