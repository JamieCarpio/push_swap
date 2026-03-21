/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:12:02 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/20 22:46:42 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void ft_sa(t_stack **a, t_bench *bench)
{
    ft_swap(a);
    write(1, "sa\n", 3);
    bench->sa++;
    bench->total++;
}

void	ft_sb(t_stack **stack_b, t_bench *bench)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
	bench->sb++;
    bench->total++;
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
	bench->ss++;
    bench->total++;
}
