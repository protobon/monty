#include "monty.h"
#include <ctype.h>

/**
  * pstr - prints the string starting at top of the stack
  * @stack: head of stack
  * @ln: line number, unused
  * Description: int stored in each element of stack is
  * treated as a character, stops printing when stack
  * is over, element is 0 or not in ascii table
  */
void pstr(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *tmp = NULL;

	if (!stack || !(*stack))
		putchar('\n');
	tmp = *stack;
	while (tmp)
	{
		if ((isascii(tmp->n) == 0) || (tmp->n == 0))
		{
			putchar('\n');
			break;
		}
		putchar(tmp->n);
		tmp = tmp->next;
	}
}
