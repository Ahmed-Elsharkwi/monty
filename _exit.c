#include"monty.h"
/**
 * _free_1 - free the stack
 */
void _free_1(void)
{
	free(top_2.buffer);
	if (top_2.holder != NULL)
	{
		while (top_2.holder->prev != NULL)
		{
			top_2.holder = top_2.holder->prev;
			free(top_2.holder->next);
		}
		free(top_2.holder);
	}
	fclose(top_2.fp);
}
