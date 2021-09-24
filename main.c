#include "monty.h"

/**
  * usage_error - prints error message
  * Description: prints message when wrong use
  * of program, exit failure
  */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
  * main - reads monty file from stdin
  * @ac: argument count, always 2
  * @av: argument vector, holds program name and filename
  * Return: always 0
  */
int main(int ac, char **av)
{
	FILE *fp;
	char *line = NULL, *tok = NULL;
	size_t len = 0;
	unsigned int ln = 1;
	ssize_t read;
	stack_t *stack = NULL;

	global.data_struct = 1;
	if (ac != 2)
		usage_error();

	fp = fopen(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (*line == '\n')
		{
			ln++;
			continue;
		}
		tok = strtok(line, " \t\n");
		if (!tok || *tok == '#')
		{
			ln++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, tok, ln);
		ln++;
	}
	fclose(fp);
	if (line)
		free(line);
	free_stack(stack);
	return (0);
}
