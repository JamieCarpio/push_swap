/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:54:20 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 01:15:50 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	execute_strategy(const char *strategy,
	t_stack **a, t_stack **b, t_bench *bench)
{
	if (ft_strcmp(strategy, "--simple") == 0)
		ft_bubble_sort(a, bench);
	else if (ft_strcmp(strategy, "--medium") == 0)
		ft_chunk_sort(a, b, bench);
	else if (ft_strcmp(strategy, "--complex") == 0)
		ft_radix_sort(a, b, bench);
	else
		ft_adaptive_sort(a, b, bench);
}

static t_stack	*init_stack_from_args(char **numbers, int count)
{
	t_stack	*stack;

	ft_check_input(count, numbers);
	stack = ft_init_stack(count, numbers);
	ft_index_stack(stack);
	return (stack);
}

static void	clean_context(t_context *ctx)
{
	ft_free_stack(&ctx->a);
	ft_free_stack(&ctx->b);
	ft_free_split(ctx->numbers);
}

static void	init_context(t_context *ctx)
{
	ctx->a = NULL;
	ctx->b = NULL;
	ctx->numbers = NULL;
	ctx->count = 0;
	ctx->bench_mode = 0;
	ctx->strategy = "--adaptive";
	ctx->disorder = 0.0;
}

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc < 2)
		return (0);
	init_context(&ctx);
	detect_flags(argc, argv, &ctx.strategy, &ctx.bench_mode);
	ctx.numbers = build_numbers(argc, argv);
	ctx.count = count_numbers(ctx.numbers);
	ctx.a = init_stack_from_args(ctx.numbers, ctx.count);
	if (ft_is_sorted(ctx.a))
		return (clean_context(&ctx), 0);
	ctx.disorder = ft_disorder(ctx.a);
	ft_bzero(&ctx.bench, sizeof(t_bench));
	execute_strategy(ctx.strategy, &ctx.a, &ctx.b, &ctx.bench);
	if (ctx.bench_mode)
		ft_print_benchmark(ctx.a, &ctx.bench,
			ctx.disorder, ctx.strategy);
	clean_context(&ctx);
	return (0);
}
