#include "monty.h"

/**
 * pall - fun that print the stack
 * @h: pointer to the first element in the list
 * @line_number: num of lines
 */
void pall(stack_t **h, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *h;
	int i;

	if (temp == NULL)
		return;

	for (i = 0; temp; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - fun that print the top element in the stack
 * @h: pointer to the first element in the list
 * @line_number: num of lines
 */
void pint(stack_t **h, unsigned int line_number)
{

	if (*h != NULL)
		printf("%d\n", (*h)->n);
	else
		_error(2, line_number, NULL);
}

/**
 * pop - fun that removes the top element in the stack
 * @h: pointer to the first element in the list
 * @line_number: num of lines
 */
void pop(stack_t **h, unsigned int line_number)
{
	stack_t *temp = *h, *nxtNode = NULL/* , *prvNode = NULL */;

	if (temp == NULL)
		_error(4, line_number, NULL);

	nxtNode = temp->next; /* points to the next node */
	if (nxtNode != NULL)
		nxtNode->prev = temp->prev; /* next node points to the prv node */
	*h = nxtNode; /* head points to the next node */
	free(temp);
}

/**
 * swap - fun that swap the top two elements in the stack
 * @h: pointer to the first element in the list
 * @line_number: num of lines
 */
void swap(stack_t **h, unsigned int line_number)
{
	stack_t *nxtNode;

	if (top < 1)
		_error(5, line_number, NULL);

	nxtNode = (*h)->next;
	(*h)->next = nxtNode->next;
	(*h)->prev = nxtNode;
	nxtNode->next = *h;
	nxtNode->prev = NULL;
	*h = nxtNode;
}

/**
 * add - fun that add top two elements in  the stack
 * @h: pointer to the first element in the list
 * @line_number: num of lines
 */
void add(stack_t **h, unsigned int line_number)
{
	stack_t *nxtNode;

	if (top < 1)
		_error(6, line_number, NULL);
	nxtNode = (*h)->next;
	nxtNode->n += (*h)->n;
	pop(h, line_number);
}
