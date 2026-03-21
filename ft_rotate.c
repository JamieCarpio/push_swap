/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:50:21 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/20 22:46:37 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_ra(t_stack **stack_a, t_bench *bench)
{
	ft_rotate(stack_a);
	write (1, "ra\n", 3);
	bench->ra++;
    bench->total++;
}

void	ft_rb(t_stack **stack_b, t_bench *bench)
{
	ft_rotate(stack_b);
	write (1, "rb\n", 3);
	bench->rb++;
    bench->total++;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
	bench->rr++;
    bench->total++;
}
