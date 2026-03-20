#include "push_swap.h"

void	ft_adaptive_sort(t_stack **a, t_stack **b)
{
	double	disorder;

	disorder = ft_disorder(*a);
	if (disorder < 0.2)
		ft_bubble_sort(a);     // O(n²)
	else if (disorder < 0.5)
		ft_chunk_sort(a, b);   // O(n√n)
	else
		ft_radix_sort(a, b);   // O(n log n)
}