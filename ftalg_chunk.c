/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftalg_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:54:10 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/21 21:55:02 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	ft_push_back(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = ft_find_max_pos(*b);
		size = ft_stack_size(*b);
		if (pos <= size / 2)
			while (pos-- > 0)
				ft_rb(b, bench);
		else
			while (pos < size)
			{
				ft_rrb(b, bench);
				pos++;
			}
		ft_pa(a, b, bench);
	}
}

void	ft_chunk_sort(t_stack **a, t_stack **b, t_bench *bench)
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
			ft_pb(a, b, bench);
			ft_rb(b, bench);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			ft_pb(a, b, bench);
			i++;
		}
		else
			ft_ra(a, bench);
	}
	ft_push_back(a, b, bench);
}