#include "push_swap.h"
#include <stdio.h>

void ft_print_benchmark(t_stack *a, t_bench *bench, double disorder, const char *strategy_name)
{
    if (!bench || !strategy_name)
        return;

    printf("\n--- BENCHMARK ---\n");
    printf("Disorder: %.2f\n", disorder);
    printf("Strategy: %s\n", strategy_name);
    printf("Total operations: %d\n", bench->total);
    printf("sa: %d\n", bench->sa);
    printf("sb: %d\n", bench->sb);
    printf("ss: %d\n", bench->ss);
    printf("pa: %d\n", bench->pa);
    printf("pb: %d\n", bench->pb);
    printf("ra: %d\n", bench->ra);
    printf("rb: %d\n", bench->rb);
    printf("rr: %d\n", bench->rr);
    printf("rra: %d\n", bench->rra);
    printf("rrb: %d\n", bench->rrb);
    printf("rrr: %d\n", bench->rrr);

    // Mostrar stack final
    printf("Stack A final: ");
    while (a)
    {
        printf("%d(index:%d)", a->value, a->index);
        if (a->next)
            printf(" -> ");
        a = a->next;
    }
    printf(" -> NULL\n");
}