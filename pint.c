#include "monty.h"

void pint(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	if (!stack)
		fprintf(stderr, "Stack empty\n");
	printf("%d\n", (*stack)->n);
}
