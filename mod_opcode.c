#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: no return
 */
void f_mod(stack_t **stack_head, unsigned int num_count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", num_count);
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

	aux = p->next->n % p->n;
	p->next->n = aux;
	*stack_head = p->next;
	free(p);
}
