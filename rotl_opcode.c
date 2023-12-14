#include "monty.h"

/**
 * s_rotl - rotates the stack to the top
 * @stack_head: pointer to the stack head
 * @num_count: line number (unused)
 * Return: No return value
 */
void s_rotl(stack_t **stack_head, __attribute__((unused)) unsigned int num_count)
{
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
	return;
	}
	stack_t *temp = *stack_head;
	stack_t *aux = (*stack_head)->next;

	aux->prev = NULL;

	while (temp->next != NULL)
	{
	temp = temp->next;
	}
	temp->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = temp;
	(*stack_head) = aux;
}
