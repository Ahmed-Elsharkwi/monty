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
	ssize_t number;

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
		get_the_func(arg[0], arg[1], line_number);
		line_number++;
	}
	_free_1();
	return (0);
}
