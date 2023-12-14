#include "monty.h"

/**
 * s_sub - subtracts the top element of the stack from the second top element.
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: No return value
 */
void s_sub(stack_t **stack_head, unsigned int num_count)
{
	stack_t *aux;
	int diff, nodes;

	aux = *stack_head;

	for (nodes = 0; aux != NULL; nodes++)
	aux = aux->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = *stack_head;

	diff = aux->next->n - aux->n;
	aux->next->n = diff;

	*stack_head = aux->next;

	free(aux);
}
