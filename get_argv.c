#include "monty.h"
/**
 * check_begin_space - fun that delete the spaces from
 * the begining of line
 * @line: pointer to string we want to check
 * Return: pointer to newline
 */
void check_begin_space(char **line)
{
	char *newline = NULL;
	unsigned int spaces = 0, i;

	newline = malloc(sizeof(char) * (strlen(*line) + 1));
	if (newline == NULL)
		_error(3, 0, NULL);

	strcpy(newline, *line);
	for (i = 0; newline[i] == ' '; i++)
		;
	spaces = strlen(newline) - i;

	*line = malloc(sizeof(char) * (spaces + 1));
	if (*line == NULL)
		_error(3, 0, NULL);

	strcpy(*line, &newline[i]);

	free(newline);
}

/**
 * get_argv - fun that splite string with a given seprator
 * @line: pointer to string we want to splite
 * @seprator: pointer to str of the seprator
 * Return: array of strings
 */
char **get_argv(char *line, char *seprator)
{
	char *token = NULL, *cpline = NULL;
	char **strings = NULL;
	int lines = 0, i;
	/* check for spaces in the begining of a line */
	check_begin_space(&line);
	if (strlen(line) == 0)
		return (NULL);

	cpline = malloc(sizeof(char) * (strlen(line) + 1));
	if (cpline == NULL)
		_error(3, 0, NULL);
	strcpy(cpline, line); /* calc how many strings to allcate it  */
	token = strtok(cpline, seprator);
	while (token != NULL)
	{
		lines++;
		token = strtok(NULL, seprator);
	}
	strings = malloc(sizeof(char *) * (lines + 1));
	if (strings == NULL)
		_error(3, 0, NULL);
	token = strtok(line, seprator); /* splite the line into strings */
	i = 0;
	while (token != NULL)
	{	/* allocate memory for each string */
		strings[i] = malloc(sizeof(char) * strlen(token));
		if (strings[i] == NULL)
		{
			for (i = 0; i < lines; i++)
				free(strings[i]);
			free(strings);
			_error(3, 0, NULL);
		}
		strings[i] = token;/* make each string points to token */
		token = strtok(NULL, seprator);
		i++;
	}
	strings[i] = NULL;/* make last element equal NULL */
	free(token), free(cpline);
	return (strings);
}
