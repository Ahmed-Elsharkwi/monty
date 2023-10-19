#include "monty.h"
/**
 * pop -  removes the top element of the stack.
 * @stack: is a pointer to stack
 * @line_number: is a line number
 */
void pop (stack_t **stack, unsigned int line_number)
{
	*stack = top_2.holder;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		_free_1();
		exit(EXIT_FAILURE);
	}
	top_2.holder = top_2.holder->prev;
	free(*stack);
}
