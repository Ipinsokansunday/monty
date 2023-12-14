#include "monty.h"

/**
 * s_pall - prints the elements of the stack
 * @stack_head: pointer to the stack head
 * @num_count: line number (not used)
 * Return: no return
 */
void s_pall(stack_t **stack_head, unsigned int num_count)
{
	stack_t *p;
	(void)num_count;

	p = *stack_head;

	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
