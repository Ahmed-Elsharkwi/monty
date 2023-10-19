#include"monty.h"
/**
 * pall_int - print all elements of the list
 * @new: is a pointer for the list
 * @line_number: is an int
 */
void pall_int(stack_t **new, unsigned int line_number)
{
	(void) line_number;

	while (*new != NULL)
	{
		printf("%d\n", (*new)->n);
		*new = (*new)->prev;
	}
}
