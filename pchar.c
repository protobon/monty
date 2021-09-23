#include "monty.h"

void pchar(stack_t **stack, unsigned int ln)
{
	int a;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		exit (EXIT_FAILURE);
	}
	a = (*stack)->n;
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		printf("%c\n", a);
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
}
