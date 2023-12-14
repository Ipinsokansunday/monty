#include "monty.h"

/**
 * s_add - adds the top two elements of the stack.
 * @stack_head: stack head
 * @num_count: line_number
 * Return: no return
 */
void s_add(stack_t **stack_head, unsigned int num_count)
{
	stack_t *p;
	int length = 0, sum;

	p = *stack_head;

	while (p)
	{
		p = p->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	p = *stack_head;
	sum = p->n + p->next->n;
	p->next->n = sum;
	*stack_head = p->next;
	free(p);
}
