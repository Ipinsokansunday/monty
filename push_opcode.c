#include "monty.h"

/**
 * s_push - adds a node to the stack or queue
 * @stack_head: pointer to the stack head
 * @num_count: line number
 * Return: No return value
 */
void s_push(stack_t **stack_head, unsigned int num_count)
{
	int n, index = 0, invalid_num = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
		index++;

		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
			invalid_num = 1;
		}
		if (invalid_num == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);

	if (bus.lifi == 0)
	add_node(stack_head, n);
	else
	add_queue(stack_head, n);
}

