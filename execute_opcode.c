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
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"adde", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
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
