#include"monty.h"
stack_p top_2;
int is_number(char *str);
/**
 * main - monty compiler
 * @argc: is an int
 * @argv: is an array of strings
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;
	unsigned int line_number = 1;
	char *arg[3];
	size_t n = 0;
	stack_t *p = NULL;
	ssize_t number;
	instruction_t arr[] = {
		{"push", push_int},
		{"pall", pall_int}
	};

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	top_2.fp = fopen(argv[1], "r");
	if (top_2.fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((number = getline(&top_2.buffer, &n, top_2.fp)) != -1)
	{
		if (check_space() == 1)
		{
			line_number++;
			continue;
		}
		arg[0] = strtok(top_2.buffer, " \n\t");
		i = 0;
		while (arg[i] != NULL && i < 2)
		{
			i++;
			arg[i] = strtok(NULL, " \n");
		}
		if (arg[1] != NULL && arg[2] != NULL)
		{
			line_number++;
			continue;
		}
		else if (strcmp(arg[0], (arr[0].opcode)) == 0)
		{
			if (arg[1] == NULL || is_number(arg[1]) == 0)
			{
				printf("L%d: usage: push integer\n", line_number);
				_free_1();
				exit(EXIT_FAILURE);
			}
			top_2.data = atoi(arg[1]);
			arr[0].f(&top_2.top_1, line_number);
		}
		else if (strcmp(arg[0], (arr[1].opcode)) == 0)
		{
			p = top_2.top_1;
			arr[1].f(&p, line_number);
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_number, arg[0]);
			_free_1();
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	_free_1();
	return (0);
}
/**
 * is_number - check if the string is integer
 * @str: is a string
 * Return: 0 if the string is not integer otherwise 1
 */
int is_number(char *str)
{
	unsigned long int i;

	for (i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
