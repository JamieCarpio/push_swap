/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:02:48 by sbouzian          #+#    #+#             */
/*   Updated: 2026/03/23 01:52:10 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	total_words(int argc, char **argv)
{
	int		i;
	int		total;
	char	**split;
	int		j;

	i = 1;
	total = 0;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		j = 0;
		while (split[j])
		{
			total++;
			j++;
		}
		ft_free_split(split);
	}
	return (total);
}

static void	fill_result(char **result, int argc, char **argv)
{
	int		i;
	int		k;
	char	**split;
	int		j;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		j = 0;
		while (split[j])
			result[k++] = ft_strdup(split[j++]);
		ft_free_split(split);
	}
	result[k] = NULL;
}

char	**parse_args(int argc, char **argv)
{
	char	**result;
	int		total;

	total = total_words(argc, argv);
	result = malloc(sizeof(char *) * (total + 1));
	if (!result)
		return (NULL);
	fill_result(result, argc, argv);
	return (result);
}
