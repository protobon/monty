#include "monty.h"

void pint(stack_t **stack, unsigned int ln)
{
	if (!stack)
		fprintf(stderr, "L%d: can't print, stack empty\n", ln);
	if (*stack)
		printf("%d\n", (*stack)->n);
}
