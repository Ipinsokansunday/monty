#include "monty.h"

/**
 * s_mul - multiplies the top two elements of the stack
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: no return
 */
void s_mul(stack_t **stack_head, unsigned int num_count)
{
	stack_t *p;
	int length = 0, aux;

	p = *stack_head;

	while (p)
	{
		p = p->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	p = *stack_head;
	aux = p->next->n * p->n;
	p->next->n = aux;
	*stack_head = p->next;
	free(p);
}
