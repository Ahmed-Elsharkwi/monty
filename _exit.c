#include"monty.h"
/**
 * _free_1 - free the stack
 */
void _free_1()
{
	free(top_2.buffer);
	if (top_2.top_1 != NULL)
	{
		while (top_2.top_1->prev != NULL)
		{
			top_2.top_1 = top_2.top_1->prev;
			free(top_2.top_1->next);
		}
		free(top_2.top_1);
	}
	fclose(top_2.fp);
}
