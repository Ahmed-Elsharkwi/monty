#include"monty.h"
/**
 * pint_int - print the element in the top of the stack
 * @stack: is a pointer
 * @line_number: is a the line number
 */
void pint_int (stack_t **stack, unsigned int line_number)
{
	*stack = top_2.holder;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		_free_1();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
