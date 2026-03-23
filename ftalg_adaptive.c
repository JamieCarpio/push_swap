/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftalg_adaptive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:54:04 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 00:09:18 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	disorder = ft_disorder(*a);
	if (disorder < 0.2)
		ft_bubble_sort(a, bench);
	else if (disorder < 0.5)
		ft_chunk_sort(a, b, bench);
	else
		ft_radix_sort(a, b, bench);
}
