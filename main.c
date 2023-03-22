#include "monty.h"

stack_t *stack = NULL;

/**
 * free_dlistint - fun that free linked list
 * @head: pointer to the first of the element of list
 */
void free_stack(stack_t *head)
{
	stack_t *temp = head;

	while (temp)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
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
	int line_number = 0, len = 1024;
	char *line = NULL;
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
		line = malloc(sizeof(char) * len);
		if (line == NULL)
			_error(3, line_number, NULL);

		while (fgets(line, len, fd) != NULL)
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
		free(line), free(argv);
		free(stack);
		fclose(fd);
	}

	return (0);
}

