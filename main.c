/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:54:20 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/22 19:03:59 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <string.h>

static int  is_flag(char *arg)
{
    return (
        strcmp(arg, "--simple") == 0 ||
        strcmp(arg, "--medium") == 0 ||
        strcmp(arg, "--complex") == 0 ||
        strcmp(arg, "--adaptive") == 0 ||
        strcmp(arg, "--bench") == 0
    );
}

static void detect_flags(int argc, char **argv,
                        const char **strategy_flag,
                        int *bench_mode)
{
    int i = 1;

    while (i < argc)
    {
        if (strcmp(argv[i], "--simple") == 0)
            *strategy_flag = "--simple";
        else if (strcmp(argv[i], "--medium") == 0)
            *strategy_flag = "--medium";
        else if (strcmp(argv[i], "--complex") == 0)
            *strategy_flag = "--complex";
        else if (strcmp(argv[i], "--adaptive") == 0)
            *strategy_flag = "--adaptive";
        else if (strcmp(argv[i], "--bench") == 0)
            *bench_mode = 1;
        i++;
    }
}

static char **build_numbers(int argc, char **argv)
{
    char    *joined;
    char    **numbers;
    char    *tmp;
    int     i;

    joined = ft_strdup("");
    if (!joined)
        ft_error();

    i = 1;
    while (i < argc)
    {
        if (!is_flag(argv[i]))
        {
            tmp = joined;
            joined = ft_strjoin(joined, argv[i]);
            free(tmp);

            tmp = joined;
            joined = ft_strjoin(joined, " ");
            free(tmp);
        }
        i++;
    }
    numbers = ft_split(joined, ' ');
    free(joined);
    if (!numbers || !numbers[0])
        ft_error();
    return (numbers);
}

static int  count_numbers(char **numbers)
{
    int i = 0;

    while (numbers[i])
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    t_stack     *stack_a;
    t_stack     *stack_b;
    char        **numbers;
    int         count;
    int         bench_mode;
    const char  *strategy_flag;
    double      disorder;
    t_bench     bench;

    stack_a = NULL;
    stack_b = NULL;
    bench_mode = 0;
    strategy_flag = "--adaptive";

    if (argc < 2)
        return (0);

    // 1️⃣ Detect flags
    detect_flags(argc, argv, &strategy_flag, &bench_mode);

    // 2️⃣ Build numbers (soporta "1 2 3")
    numbers = build_numbers(argc, argv);

    // 3️⃣ Count
    count = count_numbers(numbers);

    // 4️⃣ Validate
    ft_check_input(count, numbers);

    // 5️⃣ Init stack
    stack_a = ft_init_stack(count, numbers);

    // 6️⃣ Index
    ft_index_stack(stack_a);

    // 7️⃣ Already sorted
    if (ft_is_sorted(stack_a))
    {
        ft_free_stack(&stack_a);
        ft_free_split(numbers);
        return (0);
    }

    // 8️⃣ Disorder
    disorder = ft_disorder(stack_a);

    // 9️⃣ Init bench
    ft_bzero(&bench, sizeof(t_bench));

    // 🔟 Execute strategy
    if (strcmp(strategy_flag, "--simple") == 0)
        ft_bubble_sort(&stack_a, &bench);
    else if (strcmp(strategy_flag, "--medium") == 0)
        ft_chunk_sort(&stack_a, &stack_b, &bench);
    else if (strcmp(strategy_flag, "--complex") == 0)
        ft_radix_sort(&stack_a, &stack_b, &bench);
    else
        ft_adaptive_sort(&stack_a, &stack_b, &bench);

    // 1️⃣1️⃣ Benchmark
    if (bench_mode)
        ft_print_benchmark(stack_a, &bench, disorder, strategy_flag);

    // 1️⃣2️⃣ Free
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    ft_free_split(numbers);

    return (0);
}