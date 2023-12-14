#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: no return
 */
void f_pstr(stack_t **stack_head, unsigned int num_count)
{
	stack_t *p;
	(void)num_count;

	p = *stack_head;

	while (p != NULL && p->n > 0 && p->n <= 127)
	{
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}
