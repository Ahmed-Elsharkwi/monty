#include"monty.h"
/**
 * swap - swap two numbers
 * @stack: is the pointer of the stack
 * @line_number: is the line_number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	*stack = top_2.holder;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		_free_1();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->prev;
	temp = top_2.holder->n;
	top_2.holder->n = (*stack)->n;
	(*stack)->n = temp;
}
