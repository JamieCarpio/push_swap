#include "push_swap.h"

void	ft_adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	disorder = ft_disorder(*a);
	if (disorder < 0.2)
		ft_bubble_sort(a, bench);     // O(n²)
	else if (disorder < 0.5)
		ft_chunk_sort(a, b, bench);   // O(n√n)
	else
		ft_radix_sort(a, b, bench);   // O(n log n)
}