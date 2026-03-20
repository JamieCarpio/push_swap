#include "push_swap.h"

static int	ft_find_max_pos(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	max = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

static void	ft_push_back(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = ft_find_max_pos(*b);
		size = ft_stack_size(*b);
		if (pos <= size / 2)
			while (pos-- > 0)
				ft_rb(b);
		else
			while (pos < size)
			{
				ft_rrb(b);
				pos++;
			}
		ft_pa(a, b);
	}
}

void	ft_chunk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk;
	int	i;

	size = ft_stack_size(*a);
	chunk = sqrt(size);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			ft_pb(a, b);
			ft_rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			ft_pb(a, b);
			i++;
		}
		else
			ft_ra(a);
	}
	ft_push_back(a, b);
}