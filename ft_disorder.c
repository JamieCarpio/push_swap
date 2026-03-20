#include "push_swap.h"

double	ft_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	size_t		mistakes;
	size_t		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->index > j->index)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.00);
	return ((double)mistakes / total_pairs);
}