#include "monty.h"

/**
 * s_queue - sets the stack mode to queue
 * @stack_head: pointer to the stack head
 * @num_count: line number (unused)
 * Return: No return value
 */
void s_queue(stack_t **stack_head, unsigned int num_count)
{
	(void)stack_head;
	(void)num_count;
	bus.lifi = 1;
}

/**
 * add_queue - adds a node to the tail of the stack
 * @stack_head: pointer to the stack head
 * @n: new value
 * Return: No return value
 */
void add_queue(stack_t **stack_head, int n)
{
	stack_t *new_node, *aux;

	aux = *stack_head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
		aux = aux->next;
	}
	if (!aux)
	{
		*stack_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
	aux->next = new_node;
	new_node->prev = aux;
	}
}
