/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:52:50 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/22 00:05:24 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// ---------- utils ----------

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);
}

// imprime número con padding (alineación)
static void	ft_putnbr_pad(int n, int width)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = n;
	if (tmp <= 0)
		len = 1;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	while (len < width)
	{
		write(2, " ", 1);
		len++;
	}
	ft_putnbr_fd(n, 2);
}

// porcentaje con 2 decimales
static void	ft_putpercent(double d)
{
	int	int_part;
	int	decimal;

	int_part = (int)(d * 100);
	decimal = (int)(d * 10000) % 100;

	ft_putnbr_fd(int_part, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%", 1);
}

// ---------- strategy pretty ----------

static void	ft_print_strategy(const char *flag, double disorder)
{
	if (!flag)
		return ;

	if (flag[2] == 's') // --simple
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (flag[2] == 'm') // --medium
		ft_putstr_fd("Chunk-based / O(n√n)\n", 2);
	else if (flag[2] == 'c') // --complex
		ft_putstr_fd("Radix / O(n log n)\n", 2);
	else
	{
		// Adaptive
		if (disorder < 0.2)
			ft_putstr_fd("Adaptive (Simple) / O(n^2)\n", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("Adaptive (Chunk-based) / O(n√n)\n", 2);
		else
			ft_putstr_fd("Adaptive (Radix) / O(n log n)\n", 2);
	}
}

// ---------- main benchmark ----------

void	ft_print_benchmark(t_stack *a, t_bench *bench, double disorder, const char *strategy_name)
{
	(void)a;

	if (!bench)
		return ;

	// Disorder
	ft_putstr_fd("[bench] disorder:\t", 2);
	ft_putpercent(disorder);
	write(2, "\n", 1);

	// Strategy
	ft_putstr_fd("[bench] strategy:\t", 2);
	ft_print_strategy(strategy_name, disorder);

	// Total ops
	ft_putstr_fd("[bench] total_ops:\t", 2);
	ft_putnbr_fd(bench->total, 2);
	write(2, "\n", 1);

	// Línea 1
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_pad(bench->sa, 5);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_pad(bench->sb, 5);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_pad(bench->ss, 5);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_pad(bench->pa, 5);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_pad(bench->pb, 5);
	write(2, "\n", 1);

	// Línea 2
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_pad(bench->ra, 5);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_pad(bench->rb, 5);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_pad(bench->rr, 5);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_pad(bench->rra, 5);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_pad(bench->rrb, 5);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_pad(bench->rrr, 5);
	write(2, "\n", 1);
}