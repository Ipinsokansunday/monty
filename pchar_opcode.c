#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack, followed by a new line
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: no return
 */
void f_pchar(stack_t **stack_head, unsigned int num_count)
{
	stack_t *p;

	p = *stack_head;

	if (!p)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	if (p->n > 127 || p->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", p->n);
}
