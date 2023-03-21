#include "monty.h"

/**
 * is_empty - fun that check if the stack is empty
 * Return: 1 if empty, -1 otherwise
 */
int is_empty(void)
{
	if (top == -1)
		return (1);
	return (-1);
}

/**
 * digits_only - fun that check if the argv is int ot not
 * @s: pointer to str
 * Return: 0 if not int, 1 otherwise
 */
int digits_only(const char *s)
{
	while (*s)
	{
		if (isalpha(*s++) != 0)
			return (0);
	}
	return (1);
}
/**
 * push - fun that push int to the stack
 * @argv: str of argv
 * @head: pointer to the head of the stack
 * @line_number: num of opcode line
 */
void push(char *argv, stack_t **head, unsigned int line_number)
{
	stack_t *newNode = NULL;

	/* create new node */
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		_error(3, 0, NULL);

	if (digits_only(argv) == 0)
	{
		_error(4, line_number, NULL);
	}
	newNode->n = atoi(argv); /* fill the new node with elements */
	newNode->prev = NULL; /* make the perv points to null */

	if (is_empty() == 1)
	{
		*head = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *head; /* new node points to the next node */
		(*head)->prev = newNode; /* current node point to the new one */
		*head = newNode; /* the head points to the new node  */
	}
	top++;
}
