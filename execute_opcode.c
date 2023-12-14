#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @num_count: line_counter
 * @file: pointer to Monty file
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int num_count, FILE *file)
{
	instruction_t opst[] = {
				{"push", s_push}, {"pall", s_pall}, {"pint", s_pint},
				{"pop", s_pop},
				{"swap", s_swap},
				{"add", s_add},
				{"nop", s_nop},
				{"sub", s_sub},
				{"div", s_div},
				{"mul", s_mul},
				{"mod", s_mod},
				{"pchar", s_pchar},
				{"pstr", s_pstr},
				{"rotl", s_rotl},
				{"rotr", s_rotr},
				{"queue", s_queue},
				{"stack", s_stack},
				{NULL, NULL}
				};

	unsigned int x = 0;
	char *op;

	op = strtok(content, " \n\t");

	if (op && op[0] == '#')
	return (0);

	bus.arg = strtok(NULL, " \n\t");

	while (opst[x].opcode && op)
	{
	if (strcmp(op, opst[x].opcode) == 0)
	{
		opst[x].f(stack, num_count);
		return (0);
	}
	x++;
	}
	if (op && opst[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", num_count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
