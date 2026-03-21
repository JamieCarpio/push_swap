/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:20:51 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/21 21:54:54 by jacarpio         ###   ########.fr       */
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
    int sa, sb, ss;
    int pa, pb;
    int ra, rb, rr;
    int rra, rrb, rrr;
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
void	ft_sa(t_stack **stack_a, t_bench *bench);
void	ft_sb(t_stack **stack_b, t_bench *bench);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

void	ft_push(t_stack **stack_from, t_stack **stack_to);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a, t_bench *bench);
void	ft_rb(t_stack **stack_b, t_bench *bench);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

void	ft_revrotate(t_stack **stack);
void	ft_rra(t_stack **stack_a, t_bench *bench);
void	ft_rrb(t_stack **stack_b, t_bench *bench);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

/* ================== SORTING ================== */

void	ft_bubble_sort(t_stack **a, t_bench *bench);
void	ft_chunk_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);

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