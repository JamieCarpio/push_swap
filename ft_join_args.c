/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 23:46:35 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 18:42:07 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char	*ft_join_args(int argc, char **argv)
{
	char	*tmp;
	char	*result;
	int		i;

	result = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		tmp = result;
		result = ft_strjoin(result, argv[i]);
		free(tmp);
		tmp = result;
		result = ft_strjoin(result, " ");
		free(tmp);
		i++;
	}
	return (result);
}
