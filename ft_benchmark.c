/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:52:50 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/21 21:55:24 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// función auxiliar simple para escribir strings
static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

// función auxiliar para imprimir enteros
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

// imprimir porcentaje con 2 decimales
static void	ft_putpercent(double d)
{
	int	int_part;
	int	decimal;

	int_part = (int)(d * 100);
	decimal = (int)((d * 10000)) % 100;

	ft_putnbr_fd(int_part, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%\n", 2);
}

void	ft_print_benchmark(t_stack *a, t_bench *bench, double disorder, const char *strategy_name)
{
	(void)a; // ya no usamos el stack final

	if (!bench || !strategy_name)
		return ;

	ft_putstr_fd("\n--- BENCHMARK ---\n", 2);

	ft_putstr_fd("Disorder: ", 2);
	ft_putpercent(disorder);

	ft_putstr_fd("Strategy: ", 2);
	ft_putstr_fd((char *)strategy_name, 2);
	write(2, "\n", 1);

	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd(bench->total, 2);
	write(2, "\n", 1);

	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	write(2, "\n", 1);

	ft_putstr_fd("sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	write(2, "\n", 1);

	ft_putstr_fd("ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	write(2, "\n", 1);

	ft_putstr_fd("pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	write(2, "\n", 1);

	ft_putstr_fd("pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n", 1);

	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	write(2, "\n", 1);

	ft_putstr_fd("rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	write(2, "\n", 1);

	ft_putstr_fd("rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	write(2, "\n", 1);

	ft_putstr_fd("rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	write(2, "\n", 1);

	ft_putstr_fd("rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	write(2, "\n", 1);

	ft_putstr_fd("rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}