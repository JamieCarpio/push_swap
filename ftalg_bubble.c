/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftalg_bubble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:54:07 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 20:16:22 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_stack **a, t_bench *bench)
{
	int	size;
	int	i;
	int	swaps;
	int	j;

	size = ft_stack_size(*a);
	while (size-- > 1)
	{
		swaps = 0;
		i = 0;
		while (i++ < size)
		{
			if ((*a)->index > (*a)->next->index)
			{
				ft_sa(a, bench);
				swaps = 1;
			}
			ft_ra(a, bench);
		}
		j = 0;
		while (j++ < size)
			ft_rra(a, bench);
		if (!swaps)
			break ;
	}
}
