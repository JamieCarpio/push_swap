/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:07:21 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 18:42:09 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (!stack_from || !*stack_from)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
	bench->pa++;
	bench->total++;
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
	bench->pb++;
	bench->total++;
}
