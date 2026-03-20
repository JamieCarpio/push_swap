/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:20:51 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/20 20:45:42 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>

/* ================== STRUCT ================== */

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int total;
} t_bench;
/* ================== STACK UTILS ================== */

int		ft_stack_size(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
void	ft_free_stack(t_stack **stack);

/* ================== DISORDER ================== */

double	ft_disorder(t_stack *a);

/* ================== BASIC OPERATIONS ================== */

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

/* ================== SORTING ================== */

void	ft_bubble_sort(t_stack **a);
void	ft_chunk_sort(t_stack **a, t_stack **b);
void	ft_radix_sort(t_stack **a, t_stack **b);
void	ft_adaptive_sort(t_stack **a, t_stack **b);

/* ================== INDEX ================== */

void	ft_index_stack(t_stack *a);

/* ================== PARSING ================== */

t_stack	*ft_init_stack(int argc, char **argv);

void	ft_error(void);
void	ft_check_input(int argc, char **argv);

int		ft_is_number(char *str);
long	ft_atol(const char *str);
int		ft_duplicates(char **argv);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);

void ft_print_benchmark(t_stack *a, t_bench *bench, double disorder, const char *strategy_name);
#endif