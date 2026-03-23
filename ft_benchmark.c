/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:52:50 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 20:15:44 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h" 

static void	ft_print_strategy(const char *flag, double disorder, int size)
{
	if (flag[2] == 's')
		ft_printf("Simple / O(n^2)\n");
	else if (flag[2] == 'm')
		ft_printf("Chunk / O(n√n)\n");
	else if (flag[2] == 'c')
		ft_printf("Radix / O(n log n)\n");
	else
	{
		if (size <= 7)
		{
			ft_printf("Adaptive\n");
			return ;
		}
		if (disorder < 0.2)
			ft_printf("Adaptive (Simple) / O(n^2)\n");
		else if (disorder < 0.5)
			ft_printf("Adaptive (Chunk) / O(n√n)\n");
		else
			ft_printf("Adaptive (Radix) / O(n log n)\n");
	}
}

void	ft_print_benchmark(t_stack *a, t_bench *bench,
	double disorder, const char *strategy_name)
{
	int	int_part;
	int	decimal;
	int	size;

	size = ft_stack_size(a);
	(void)a;
	if (!bench)
		return ;
	int_part = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	ft_printf("[bench] disorder:\t%d.", int_part);
	if (decimal < 10)
		ft_printf("0");
	ft_printf("%d%%\n", decimal);
	ft_printf("[bench] strategy:\t");
	ft_print_strategy(strategy_name, disorder, size);
	ft_printf("[bench] total_ops:\t%d\n", bench->total);
	ft_printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
