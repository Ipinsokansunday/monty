#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @stack_head: pointer to the stack head
 * @num_count: line number (unused)
 * Return: No return value
 */
void f_rotr(stack_t **stack_head, __attribute__((unused)) unsigned int num_count)
{
	stack_t *reprint;

	reprint = *stack_head;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
	return;
	}
	while (reprint->next)
	{
	reprint = reprint->next;
	}
	reprint->next = *stack_head;
	reprint->prev->next = NULL;
	reprint->prev = NULL;
	(*stack_head)->prev = reprint;
	(*stack_head) = reprint;
}
