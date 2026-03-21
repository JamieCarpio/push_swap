#include "push_swap.h"

static int	ft_get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = ft_stack_size(stack) - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_stack_size(*a);
	max_bits = ft_get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ft_ra(a, bench);
			else
				ft_pb(a, b, bench);
			j++;
		}
		while (*b)
			ft_pa(a, b, bench);
		i++;
	}
}