#include "monty.h"

int top = -1;
/**
 * main - program for monty opcode
 * @ac: num of arguments
 * @av: pointer to the array of arguments
 * Return: always 0
 */
int main(int ac, char **av)
{
	FILE *fd;
	int line_number = 0, len = 1024;
	char *line = NULL;
	char **argv = NULL;
	stack_t *stack = NULL;

	if (ac != 2) /* less than two arguments */
		_error(1, line_number, NULL);
	fd = fopen(av[1], "r"); /* open file  */
	if (fd == NULL)
		_error(7, 0, av[1]);
	else
	{
		line = malloc(sizeof(char) * len);
		if (line == NULL)
			_error(3, line_number, NULL);

		while (fgets(line, len, fd) != NULL)
		{
			line_number++; /* count the num of lines */
			if (line[strlen(line) - 1] == '\n') /* delete the extra element */
				line[strlen(line) - 1] = '\0';

			argv = get_argv(line, " "); /* get arguments of each line */
			exe_opcode(&stack, argv, line_number);
		}
		free(line), free(argv);
		fclose(fd);
	}

	return (0);
}

