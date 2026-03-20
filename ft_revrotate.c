/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:50:21 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/19 00:12:52 by jamie_ubunt      ###   ########.fr       */
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

void	ft_rra(t_stack **stack_a)
{
	ft_revrotate(stack_a);
	write (1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_revrotate(stack_b);
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
	write(1, "rrr\n", 4);
}
