#include "monty.h"

/**
 * add_node - adds a node to the start of the stack
 * @stack: stack head
 * @n: new node data
 * Return: new node, NULL if failed
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
  * add_node_queue - adds a node to the end of the stack
  * @stack: head of stack
  * @n: new node data
  * Return: new node address, NULL if failed
  */
stack_t *add_node_queue(stack_t **stack, const int n)
{
	stack_t *new = NULL, *last = *stack;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return (new);
	}
	while (last->next)
		last = last->next;

	last->next = new;
	new->prev = last;
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
