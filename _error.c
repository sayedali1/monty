#include "monty.h"

/**
 * _error - fun that print error message
 * @exit_num: num of exit
 * @line_number: num of line of code
 * @av: array of arguments
 */
void _error(int exit_num, unsigned int line_number, char *av)
{
	switch (exit_num)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "L %d: can't pint, stack empty\n", line_number);
		break;
	case 3:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 4:
		fprintf(stderr, "L %d: can't pop an empty stack\n", line_number);
		break;
	case 5:
		fprintf(stderr, "L %d: can't swap, stack too short\n", line_number);
		break;
	case 6:
		fprintf(stderr, "L %d: can't add, stack too short\n", line_number);
		break;
	case 7:
		fprintf(stderr, "Error: Can't open file %s", av);
		exit(EXIT_FAILURE);
	default:
		break;
	}
	exit(EXIT_FAILURE);
}
