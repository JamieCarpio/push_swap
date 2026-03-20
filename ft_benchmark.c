#include "push_swap.h"
#include <stdio.h>

void ft_print_benchmark(t_stack *a, t_bench *bench, double disorder, const char *strategy_name)
{
    int size = 0;
    t_stack *tmp = a;

    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }

    fprintf(stderr, "=== BENCHMARK ===\n");
    fprintf(stderr, "Disorder: %.3f\n", disorder);
    fprintf(stderr, "Size: %d\n", size);
    fprintf(stderr, "Strategy: %s\n", strategy_name);
    fprintf(stderr, "Total operations: %d\n", bench->total);
    fprintf(stderr, "sa: %d, sb: %d, ss: %d\n", bench->sa, bench->sb, bench->ss);
    fprintf(stderr, "pa: %d, pb: %d\n", bench->pa, bench->pb);
    fprintf(stderr, "ra: %d, rb: %d, rr: %d\n", bench->ra, bench->rb, bench->rr);
    fprintf(stderr, "rra: %d, rrb: %d, rrr: %d\n", bench->rra, bench->rrb, bench->rrr);
}