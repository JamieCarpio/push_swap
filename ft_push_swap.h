/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:20:51 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/17 21:53:13 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;
/*
// initialisation

t_stack	*init_list(int argc, char **argv);
void	set_index(t_stack *head, int list_size);

// linked list functions

int		count_nodes(t_stack *head);
void	print_list(t_stack *head);
void	insert_at_tail(t_stack **head, int new_value);
t_stack	*make_new_node(int new_value);
*/
// instructions

void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **stack_from, t_stack **stack_to);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_revrotate(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
/*
// sorting

int		find_biggest(t_stack *head);
int		find_bits(int biggest_nbr);
void	sort_three(t_stack **head);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
int		sorted(t_stack **head);

// input checks

void	check_input(int argc, char **argv);
int		check_nbr(char *argv);
int		check_doubles(char **argv);

// miscellaneous

void	error_msg(char *str);
void	free_stack(t_stack **head);
int		count_arg(char **array);
*/
#endif