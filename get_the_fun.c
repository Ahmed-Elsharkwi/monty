#include"monty.h"
int is_number(char *str);
/**
 * get_the_func - get the function
 * @arg_1: is the opcode
 * @arg_2: is the number
 * @line_number: is the line number
 */
void get_the_func(char *arg_1, char *arg_2, int line_number)
{
	instruction_t arr[] = {
		{"push", push_int},
		{"pall", pall_int},
		{"pint", pint_int},
		{"pop", pop},
		{NULL, NULL}
	};
	int i = 0;

	while (arr[i].opcode != NULL)
	{
		if (strcmp(arg_1, arr[i].opcode) == 0)
		{
			if (strcmp(arg_1, "push") == 0)
			{
				if (arg_2 == NULL || is_number(arg_2) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					_free_1();
					exit(EXIT_FAILURE);
				}
				top_2.data = atoi(arg_2);
			}
			arr[i].f(&top_2.print_pointer, line_number);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, arg_1);
	_free_1();
	exit(EXIT_FAILURE);
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
