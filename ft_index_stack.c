#include "push_swap.h"

void	ft_index_stack(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		index;

	i = a;
	while (i)
	{
		index = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}