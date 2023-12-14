#include "monty.h"

/**
 * add_node - add node to the head of the stack
 * @stack_head: head of the stack
 * @n: new value
 * Return: no return
 */
void add_node(stack_t **stack_head, int n)
{
	stack_t *new_node, *aux;

	aux = *stack_head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (aux != NULL)
	{
	aux->prev = new_node;
	}
	new_node->n = n;
	new_node->next = *stack_head;
	new_node->prev = NULL;
	*stack_head = new_node;
}
