#include "push_swap.h"

void	ft_bubble_sort(t_stack **a)
{
	int	size;
	int	i;
	int	swaps;

	size = ft_stack_size(*a);
	if (size < 2)
		return ;

	i = 0;
	while (i < size)
	{
		swaps = 0;
		// Recorremos el stack hasta el último elemento no ordenado
		for (int j = 0; j < size - i - 1; j++)
		{
			if ((*a)->index > (*a)->next->index)
			{
				ft_sa(a);      // Intercambiar si están desordenados
				swaps++;
			}
			ft_ra(a);          // Rotar al siguiente par
		}
		// Después de cada pasada, traemos los elementos rotados al inicio
		for (int k = 0; k < size - i - 1; k++)
			ft_rra(a);

		// Si no hubo swaps en toda la pasada, el stack ya está ordenado
		if (swaps == 0)
			break;

		i++;
	}
}