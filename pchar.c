#include "monty.h"
#include <ctype.h>

/**
  * pchar - prints the char at the top of the stack
  * @stack: head of stack
  * @ln: line number
  * Description: prints ascii value of element at
  * top of the stack, error if stack is empty or
  * element not in ascii table
  */
void pchar(stack_t **stack, unsigned int ln)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
