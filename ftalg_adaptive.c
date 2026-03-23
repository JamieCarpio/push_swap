/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftalg_adaptive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:54:04 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 20:16:23 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size;
	double	disorder;

	size = ft_stack_size(*a);
	if (size <= 7)
	{
		ft_smallsort(a, b, bench, size);
		return ;
	}
	disorder = ft_disorder(*a);
	if (disorder < 0.2)
		ft_bubble_sort(a, bench);
	else if (disorder < 0.5)
		ft_chunk_sort(a, b, bench);
	else
		ft_radix_sort(a, b, bench);
}
