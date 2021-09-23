#include "monty.h"

/**
  * pop - removes top element of stack
  * @stack: head of stack
  * @ln: line number
  * Description: if stack is empty, print error and
  * exit failure
  */
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
