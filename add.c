#include"monty.h"
/**
 * add - add the result of addition of two numbers to stack
 * @stack: is a pointer
 * @line_number: is an int
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	*stack = top_2.holder;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free_1();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->prev;
	result = (*stack)->n + top_2.holder->n;
	pop(&top_2.print_pointer, line_number);
	pop(&top_2.print_pointer, line_number);
	top_2.data = result;
	push_int(&top_2.print_pointer, line_number);
}
