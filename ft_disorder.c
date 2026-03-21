/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:52:56 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/21 21:55:20 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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