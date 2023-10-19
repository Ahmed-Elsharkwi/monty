#include"monty.h"
/**
 * push_int - push an element into stack
 * @new: is a pointer
 * @line_number: is an int
 */
void push_int(stack_t **new, unsigned int line_number)
{
	stack_t *temp = malloc(sizeof(stack_t));
	(void) line_number;

	if (temp == NULL)
	{
		printf("Error: malloc failed\n");
		_free_1();
		exit(EXIT_FAILURE);
	}
	temp->n = top_2.data;
	*new = top_2.holder;
	if (*new == NULL)
	{
		temp->next = NULL;
		temp->prev = NULL;
		*new = temp;
	}
	else
	{
		temp->next = (*new)->next;
		(*new)->next = temp;
		temp->prev = *new;
		*new = temp;
	}
	top_2.holder = *new;
}
