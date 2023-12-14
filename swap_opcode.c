#include "monty.h"

/**
 * s_swap - swaps the top two elements of the stack.
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: No return value
 */
void s_swap(stack_t **stack_head, unsigned int num_count)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	p = *stack_head;
	aux = p->n;
	p->n = p->next->n;
	p->next->n = aux;
}
