#include "monty.h"

/**
 * add_node - adds a node to the start of the stack
 * @stack: stack head
 * @n: data for new node
 * Return: new node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}

	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
	return (new);
}

/**
 * print_stack - prints the contents of stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t c = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}

	return (c);
}

/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;
	stack_t *next;

	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
