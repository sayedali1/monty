#include "monty.h"

stack_t *stack = NULL;

/**
 * free_dlistint - fun that free linked list
 * @head: pointer to the first of the element of list
 */
void free_stack(stack_t **h)
{

	/* return if empty list */
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
/**
 * main - program for monty opcode
 * @ac: num of arguments
 * @av: pointer to the array of arguments
 * Return: always 0
 */
int main(int ac, char **av)
{
	FILE *fd;
	int line_number = 0;
	char line[100000];
	char **argv = NULL;

	if (ac != 2) /* less than two arguments */
		_error(1, line_number, NULL);
	if (av[1] == NULL)
		_error(7, 0, av[1]);
	fd = fopen(av[1], "r"); /* open file  */
	if (fd == NULL)
		_error(7, 0, av[1]);
	else
	{
		while (fgets(line, sizeof(line), fd))
		{
			line_number++; /* count the num of lines */
			if (line[strlen(line) - 1] == '\n') /* delete the extra element */
				line[strlen(line) - 1] = '\0';
			if (strlen(line) == 0)
				continue;
			argv = get_argv(line, " "); /* get arguments of each line */
			if (argv == NULL)
				continue;
			exe_opcode(&stack, argv, line_number);
		}
		free(argv);
		free_stack(&stack);
		fclose(fd);
	}

	return (0);
}

