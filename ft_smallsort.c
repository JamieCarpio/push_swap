/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:26:28 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 20:16:14 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **a, t_bench *bench)
{
	if ((*a)->index > (*a)->next->index)
		ft_sa(a, bench);
}

void	ft_sort_three(t_stack **a, t_bench *bench)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && x < z)
		ft_sa(a, bench);
	else if (x > y && y > z)
	{
		ft_sa(a, bench);
		ft_rra(a, bench);
	}
	else if (x > z && y < z)
		ft_ra(a, bench);
	else if (x < y && x > z)
		ft_rra(a, bench);
	else if (x < y && y > z)
	{
		ft_sa(a, bench);
		ft_ra(a, bench);
	}
}

static int	get_min_pos(t_stack *a)
{
	int	pos;
	int	min_pos;
	int	min;

	pos = 0;
	min_pos = 0;
	min = INT_MAX;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}

static void	sort_three_bench(t_stack **a, t_bench *bench)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && x < z)
		ft_sa(a, bench);
	else if (x > y && y > z)
	{
		ft_sa(a, bench);
		ft_rra(a, bench);
	}
	else if (x > z && y < z)
		ft_ra(a, bench);
	else if (x < y && x > z)
		ft_rra(a, bench);
	else if (x < y && y > z)
	{
		ft_sa(a, bench);
		ft_ra(a, bench);
	}
}

void	ft_smallsort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int	pos;

	while (size > 3)
	{
		pos = get_min_pos(*a);
		ft_rotate_to_pos_a(a, pos, bench);
		ft_pb(a, b, bench);
		size--;
	}
	if (size == 2)
		ft_sa(a, bench);
	else if (size == 3)
		sort_three_bench(a, bench);
	while (*b)
		ft_pa(a, b, bench);
}
