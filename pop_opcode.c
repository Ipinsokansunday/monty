#include "monty.h"

/**
 * s_pop - removes the top element of the stack
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: no return
 */
void s_pop(stack_t **stack_head, unsigned int num_count)
{
	stack_t *p;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	p = *stack_head;
	*stack_head = p->next;
	free(p);
}
