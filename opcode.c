#include "monty.h"

/**
 * opcode - runs opcode from monty file
 * @stack: doubly linked list to store data
 * @str: string to compare with opcodes
 * @ln: line number
 */
void opcode(stack_t **stack, char *str, unsigned int ln)
{
	int i = 0;
	instruction_t op[] = INSTRUCTIONS;

	if (strcmp(str, "stack") == 0)
	{
		global.data_struct = 1;
		return;
	}
	if (strcmp(str, "queue") == 0)
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, ln);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, str);
	exit(EXIT_FAILURE);
}
