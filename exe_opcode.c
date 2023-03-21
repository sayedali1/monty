#include "monty.h"

/**
 * opcode - fun that execute the opcode
 * @stack: pointer to the stack
 * @argv:pointer to arguments
 * @line_number: num of line of the opcode
 */
void exe_opcode(stack_t **stack, char **argv, unsigned int line_number)
{
	instruction_t opcodes[] = {{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {NULL, NULL}};
	int i;

	if (strcmp(argv[0], "push") == 0) /* if push opcode */
		push(argv[1], stack, line_number);
	else
	{
		for (i = 0; opcodes[i].opcode != NULL; i++)
			if (strcmp(opcodes[i].opcode, argv[0]) == 0)
				opcodes[i].f(stack, line_number);
	}
}
