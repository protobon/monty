#include "monty.h"

/**
  * rotr - rotates the stack to the bottom
  * @stack: head of stack
  * @ln: line number, unused
  * Description: the last element of the stack becomes
  * the first one, second last becomes last, never fails
  */
void rotr(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *first = *stack, *last = NULL;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	(*stack)->prev = first;
	first->next = *stack;
	first->prev = NULL;
	*stack = first;
}
