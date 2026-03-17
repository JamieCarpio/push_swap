#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ft_ra(t_stack **stack)
{
	ft_rotate(stack);
	write (1, "ra\n", 3);
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	write (1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}