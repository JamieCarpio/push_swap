/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:53:05 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/22 21:06:57 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		ft_error();
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < argc)
	{
		ft_add_back(&stack, ft_new_node(ft_atol(argv[i])));
		i++;
	}
	return (stack);
}
