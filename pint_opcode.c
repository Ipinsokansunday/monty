#include "monty.h"

/**
 * s_pint - prints the value at the top of the stack
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: no return
 */
void s_pint(stack_t **stack_head, unsigned int num_count)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
