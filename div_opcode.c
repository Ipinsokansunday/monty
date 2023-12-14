#include "monty.h"

/**
 * s_div - divides the top two elements of the stack.
 * @stack_head: stack head
 * @num_count: line_number
 * Return: no return
 */
void s_div(stack_t **stack_head, unsigned int num_count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	p = *stack_head;

	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = p->next->n / p->n;
	p->next->n = aux;
	*stack_head = p->next;
	free(p);
}
