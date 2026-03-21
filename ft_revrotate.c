/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:50:21 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/21 21:55:08 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate(t_stack **stack)
{
	t_stack	*new_last;
	t_stack *old_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	old_last = *stack;
	while (old_last->next != NULL)
	{
		new_last = old_last;
		old_last = old_last-> next;
	}
	old_last->next = *stack;
	new_last->next = NULL;
	*stack = old_last;
}

void	ft_rra(t_stack **stack_a, t_bench *bench)
{
	ft_revrotate(stack_a);
	write (1, "rra\n", 4);
	bench->rra++;
    bench->total++;
}

void	ft_rrb(t_stack **stack_b, t_bench *bench)
{
	ft_revrotate(stack_b);
	write (1, "rrb\n", 4);
	bench->rrb++;
    bench->total++;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
	write(1, "rrr\n", 4);
	bench->rrr++;
    bench->total++;
}
