/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:52:53 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/22 19:14:49 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			ft_error();
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			ft_error();
		i++;
	}
	if (ft_duplicates(argv))
		ft_error();
}

