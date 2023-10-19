#include"monty.h"
/**
 * _free_1 - free the stack
 */
void _free_1(void)
{
	free(top_2.buffer);
	if (top_2.p != NULL)
	{
		while (top_2.p->prev != NULL)
		{
			top_2.p = top_2.p->prev;
			free(top_2.p->next);
		}
		free(top_2.p);
	}
	fclose(top_2.fp);
}
